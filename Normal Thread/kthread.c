#include <linux/module.h>
#include <linux/times.h>
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/init.h>

static struct task_struct *thread_st;
// Function executed by kernel thread
static int thread_fn(void *unused)
{
	printk(KERN_INFO "Thread is Running\n");
	return 0;
}
// Module Initialization
static int __init init_thread(void)
{
	printk(KERN_INFO "Creating Thread\n");
	thread_st = kthread_run(thread_fn, NULL, "mythread");
	return 0;
}

// Module Exit
static void __exit cleanup_thread(void)
{
	printk(KERN_INFO "Cleaning Up\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam Methuselah");
MODULE_DESCRIPTION("A Simple Module for the k.threads by 19BCE1698");

module_init(init_thread);
module_exit(cleanup_thread);

