#include <linux/module.h>
#include <linux/times.h>
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include<linux/ktime.h>
#include<linux/timekeeping.h>
#include<linux/time.h>

static struct task_struct *thread_st;
struct timespec64 t1,t2;
static int thread_fn(void *unused)
{
	printk(KERN_INFO "Thread is Running\n");
	ktime_get_real_ts64(&t2);
	printk(KERN_INFO "End time= %ld nanosec\n" ,t2.tv_nsec);
	printk(KERN_INFO "Duration= %ld nanosec\n" ,t2.tv_nsec-t1.tv_nsec);
	return 0;
}
static int __init init_thread(void)
{
	ktime_get_real_ts64(&t1);
	printk(KERN_INFO "Start time= %ld nanosec\n" ,t1.tv_nsec);
	printk(KERN_INFO "Creating Thread\n");
	thread_st = kthread_run(thread_fn, NULL, "mythread");
	return 0;
}

static void __exit cleanup_thread(void)
{
	printk(KERN_INFO "Cleaning Up\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam Methuselah");
MODULE_DESCRIPTION("A Module to calculate time elapsed in Kernel Thread by 19BCE1698");

module_init(init_thread);
module_exit(cleanup_thread);
