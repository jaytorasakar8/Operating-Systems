#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x11ae19b5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x5e25804, __VMLINUX_SYMBOL_STR(__request_region) },
	{ 0xf29a148e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x1e0c2be4, __VMLINUX_SYMBOL_STR(ioremap_wc) },
	{ 0xdb90c90f, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xc364ae22, __VMLINUX_SYMBOL_STR(iomem_resource) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x8d8ad63a, __VMLINUX_SYMBOL_STR(pstore_unregister) },
	{ 0x571f8f7e, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xe464de26, __VMLINUX_SYMBOL_STR(platform_device_register_full) },
	{ 0x887fa47e, __VMLINUX_SYMBOL_STR(__getnstimeofday64) },
	{ 0xfd3def99, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x733c3b54, __VMLINUX_SYMBOL_STR(kasprintf) },
	{ 0x50d1f870, __VMLINUX_SYMBOL_STR(pgprot_writecombine) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xfb682e09, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x1916e38c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x7fc3ee6a, __VMLINUX_SYMBOL_STR(vmap) },
	{ 0xb050f329, __VMLINUX_SYMBOL_STR(init_rs) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x4604a43a, __VMLINUX_SYMBOL_STR(mem_section) },
	{ 0x53ceacf8, __VMLINUX_SYMBOL_STR(platform_device_unregister) },
	{ 0x16b021c5, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x42c8de35, __VMLINUX_SYMBOL_STR(ioremap_nocache) },
	{ 0x5944d015, __VMLINUX_SYMBOL_STR(__cachemode2pte_tbl) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x8d15114a, __VMLINUX_SYMBOL_STR(__release_region) },
	{ 0x680ec266, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x94961283, __VMLINUX_SYMBOL_STR(vunmap) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x8e2cd819, __VMLINUX_SYMBOL_STR(pstore_register) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x8a42020, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x29fa419f, __VMLINUX_SYMBOL_STR(decode_rs8) },
	{ 0x201d8ea3, __VMLINUX_SYMBOL_STR(encode_rs8) },
	{ 0xc6e393c8, __VMLINUX_SYMBOL_STR(param_ops_ulong) },
	{ 0x8ea9bed1, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x33e099ac, __VMLINUX_SYMBOL_STR(param_ops_ullong) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=reed_solomon";


MODULE_INFO(srcversion, "55A87CFB845403F104920C2");
