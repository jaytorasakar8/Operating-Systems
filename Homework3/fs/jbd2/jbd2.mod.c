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
	{ 0xb6d7ae26, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x122e6e41, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0xf29a148e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x7410aba2, __VMLINUX_SYMBOL_STR(strreplace) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x6dcb281a, __VMLINUX_SYMBOL_STR(crypto_alloc_shash) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xd705b4c7, __VMLINUX_SYMBOL_STR(schedule_hrtimeout) },
	{ 0xa0fbac79, __VMLINUX_SYMBOL_STR(wake_up_bit) },
	{ 0x16a92c4c, __VMLINUX_SYMBOL_STR(bmap) },
	{ 0x319c301e, __VMLINUX_SYMBOL_STR(filemap_fdatawait) },
	{ 0x7e24d5f2, __VMLINUX_SYMBOL_STR(seq_open) },
	{ 0xd56258a3, __VMLINUX_SYMBOL_STR(end_buffer_write_sync) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0xc06d3165, __VMLINUX_SYMBOL_STR(blkdev_issue_flush) },
	{ 0x7ab88a45, __VMLINUX_SYMBOL_STR(system_freezing_cnt) },
	{ 0x179651ac, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x531afc41, __VMLINUX_SYMBOL_STR(ll_rw_block) },
	{ 0x33a09525, __VMLINUX_SYMBOL_STR(__lock_buffer) },
	{ 0x43c3d879, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xc87c1f84, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0x5708b391, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x24fdac79, __VMLINUX_SYMBOL_STR(wake_bit_function) },
	{ 0x6f8c9737, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x5d8532ee, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x61c160c5, __VMLINUX_SYMBOL_STR(__getblk_gfp) },
	{ 0xf0852797, __VMLINUX_SYMBOL_STR(unlock_buffer) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x2084d8b1, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x32c2d725, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xf3ffba2d, __VMLINUX_SYMBOL_STR(set_bh_page) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x56705946, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0xe8ef0ff0, __VMLINUX_SYMBOL_STR(current_kernel_time64) },
	{ 0x3da1edff, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xf783b36e, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0xacecfeb6, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xa6485b04, __VMLINUX_SYMBOL_STR(freezing_slow_path) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x8f6519fd, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x4315104, __VMLINUX_SYMBOL_STR(crypto_shash_update) },
	{ 0xad1b8ab0, __VMLINUX_SYMBOL_STR(generic_writepages) },
	{ 0x4c9d28b0, __VMLINUX_SYMBOL_STR(phys_base) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xa7e3f247, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x65ad8a27, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xfee92a1a, __VMLINUX_SYMBOL_STR(__wait_on_buffer) },
	{ 0xe8db8dd2, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0x8bc1866a, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0xf3d2b1eb, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0x4b5e0e4c, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0x58e3306d, __VMLINUX_SYMBOL_STR(bit_wait_io) },
	{ 0x6b74b9be, __VMLINUX_SYMBOL_STR(bit_waitqueue) },
	{ 0x6f2e4f46, __VMLINUX_SYMBOL_STR(__cond_resched_lock) },
	{ 0xbd9074b1, __VMLINUX_SYMBOL_STR(blk_finish_plug) },
	{ 0x16b021c5, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x9b9ffa9e, __VMLINUX_SYMBOL_STR(free_buffer_head) },
	{ 0x47e2cd6, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0xd3323e84, __VMLINUX_SYMBOL_STR(sync_blockdev) },
	{ 0x278a3347, __VMLINUX_SYMBOL_STR(try_to_free_buffers) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xc0cd3b13, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0x4482cdb, __VMLINUX_SYMBOL_STR(__refrigerator) },
	{ 0xad833db9, __VMLINUX_SYMBOL_STR(crypto_destroy_tfm) },
	{ 0x50fad434, __VMLINUX_SYMBOL_STR(round_jiffies_up) },
	{ 0x7e2ac978, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x1cf21213, __VMLINUX_SYMBOL_STR(alloc_buffer_head) },
	{ 0xdd569c18, __VMLINUX_SYMBOL_STR(submit_bh) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x188c4aaf, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xe8a73aaf, __VMLINUX_SYMBOL_STR(out_of_line_wait_on_bit) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0xae69e177, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x91cc9166, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x4ff9f67a, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x1d1056e5, __VMLINUX_SYMBOL_STR(crc32_be) },
	{ 0x3bb5114a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x9e61bb05, __VMLINUX_SYMBOL_STR(set_freezable) },
	{ 0xe235b064, __VMLINUX_SYMBOL_STR(write_dirty_buffer) },
	{ 0xcbf85e68, __VMLINUX_SYMBOL_STR(__bforget) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xd47e7957, __VMLINUX_SYMBOL_STR(filemap_fdatawrite_range) },
	{ 0x1513bf3f, __VMLINUX_SYMBOL_STR(__find_get_block) },
	{ 0x45dda0fe, __VMLINUX_SYMBOL_STR(mark_buffer_dirty) },
	{ 0x6a4d99ac, __VMLINUX_SYMBOL_STR(seq_release) },
	{ 0x7d705738, __VMLINUX_SYMBOL_STR(blk_start_plug) },
	{ 0x151277aa, __VMLINUX_SYMBOL_STR(__put_page) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2EF4F80AAFE7A8F78E41D72");
