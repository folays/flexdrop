#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa8c16cf3, "module_layout" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0x3bcbbb33, "kthread_create_on_node" },
	{ 0x571ab46f, "current_task" },
	{ 0x27e1a049, "printk" },
	{ 0xda2d560c, "kthread_stop" },
	{ 0xb4390f9a, "mcount" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x939708e0, "wake_up_process" },
	{ 0xcf21d241, "__wake_up" },
	{ 0x5c8b5ce8, "prepare_to_wait" },
	{ 0xfa66f77c, "finish_wait" },
	{ 0xe5d95985, "param_ops_ulong" },
	{ 0x6d044c26, "param_ops_uint" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "B58D69CE36A34089479AD51");
