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
	{ 0xe94dd4f9, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xb6d7ae26, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x122e6e41, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0xf29a148e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x1ceea77e, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x4489da02, __VMLINUX_SYMBOL_STR(register_sysctl_table) },
	{ 0xa0fbac79, __VMLINUX_SYMBOL_STR(wake_up_bit) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x8507c383, __VMLINUX_SYMBOL_STR(proc_dointvec) },
	{ 0x5696abfc, __VMLINUX_SYMBOL_STR(kobject_uevent) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0x5708b391, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xa26d9b4f, __VMLINUX_SYMBOL_STR(workqueue_congested) },
	{ 0xe29e1d0e, __VMLINUX_SYMBOL_STR(out_of_line_wait_on_atomic_t) },
	{ 0xcd57f7b0, __VMLINUX_SYMBOL_STR(radix_tree_tag_get) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x62de687d, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xba3043c1, __VMLINUX_SYMBOL_STR(kobject_create_and_add) },
	{ 0xd3bc530e, __VMLINUX_SYMBOL_STR(out_of_line_wait_on_bit_lock) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xfe7c4287, __VMLINUX_SYMBOL_STR(nr_cpu_ids) },
	{ 0xd8ded085, __VMLINUX_SYMBOL_STR(radix_tree_maybe_preload) },
	{ 0x8833a2a8, __VMLINUX_SYMBOL_STR(__cpu_possible_mask) },
	{ 0xf783b36e, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0xacecfeb6, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x1250c7e1, __VMLINUX_SYMBOL_STR(_raw_spin_trylock) },
	{ 0xf31b3fd1, __VMLINUX_SYMBOL_STR(workqueue_set_max_active) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xa7e3f247, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0xf0a8237a, __VMLINUX_SYMBOL_STR(radix_tree_gang_lookup_tag) },
	{ 0xbc8ff6d2, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x25f897a7, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0x3c483012, __VMLINUX_SYMBOL_STR(radix_tree_delete) },
	{ 0x9f46ced8, __VMLINUX_SYMBOL_STR(__sw_hweight64) },
	{ 0x6b74b9be, __VMLINUX_SYMBOL_STR(bit_waitqueue) },
	{ 0x783b3563, __VMLINUX_SYMBOL_STR(wake_up_atomic_t) },
	{ 0x6f2e4f46, __VMLINUX_SYMBOL_STR(__cond_resched_lock) },
	{ 0x16e297c3, __VMLINUX_SYMBOL_STR(bit_wait) },
	{ 0x16b021c5, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x7985d043, __VMLINUX_SYMBOL_STR(radix_tree_tag_set) },
	{ 0xa06ff399, __VMLINUX_SYMBOL_STR(unregister_sysctl_table) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x6b2dc060, __VMLINUX_SYMBOL_STR(dump_stack) },
	{ 0x7a718643, __VMLINUX_SYMBOL_STR(__radix_tree_insert) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xc5844fb8, __VMLINUX_SYMBOL_STR(__per_cpu_offset) },
	{ 0x10950ee1, __VMLINUX_SYMBOL_STR(radix_tree_tag_clear) },
	{ 0x188c4aaf, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x99195078, __VMLINUX_SYMBOL_STR(vsnprintf) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xdad13708, __VMLINUX_SYMBOL_STR(__pagevec_release) },
	{ 0xe8a73aaf, __VMLINUX_SYMBOL_STR(out_of_line_wait_on_bit) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0xe5241f4, __VMLINUX_SYMBOL_STR(kernel_kobj) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3ea96b74, __VMLINUX_SYMBOL_STR(pagevec_lookup) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xfdfd6c90, __VMLINUX_SYMBOL_STR(add_wait_queue_exclusive) },
	{ 0x53569707, __VMLINUX_SYMBOL_STR(this_cpu_off) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x844e3767, __VMLINUX_SYMBOL_STR(radix_tree_lookup) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x8ea9bed1, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x151277aa, __VMLINUX_SYMBOL_STR(__put_page) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "FC568CBBADE88280BA7487C");
