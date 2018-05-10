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
	{ 0xe125ddb6, __VMLINUX_SYMBOL_STR(nfs_unlink) },
	{ 0x30b95d48, __VMLINUX_SYMBOL_STR(nfs_symlink) },
	{ 0xf29a148e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xaf21d88e, __VMLINUX_SYMBOL_STR(nfs_refresh_inode) },
	{ 0x3ad14240, __VMLINUX_SYMBOL_STR(nfs_close_context) },
	{ 0x65b4a4b, __VMLINUX_SYMBOL_STR(nfs_free_client) },
	{ 0xd154dd95, __VMLINUX_SYMBOL_STR(nfs_try_mount) },
	{ 0x73c0fb8f, __VMLINUX_SYMBOL_STR(nfs_permission) },
	{ 0x97595953, __VMLINUX_SYMBOL_STR(nfs_link) },
	{ 0x23a99389, __VMLINUX_SYMBOL_STR(xdr_inline_pages) },
	{ 0x76ec3306, __VMLINUX_SYMBOL_STR(init_user_ns) },
	{ 0xa573dfd0, __VMLINUX_SYMBOL_STR(nfs_instantiate) },
	{ 0x679ee3b3, __VMLINUX_SYMBOL_STR(nfs_sops) },
	{ 0x6df2a58d, __VMLINUX_SYMBOL_STR(nfs_setattr_update_inode) },
	{ 0xdef87326, __VMLINUX_SYMBOL_STR(unregister_nfs_version) },
	{ 0x7504f494, __VMLINUX_SYMBOL_STR(nfs_rmdir) },
	{ 0xa7e4ce5, __VMLINUX_SYMBOL_STR(xdr_reserve_space) },
	{ 0xfb7ee006, __VMLINUX_SYMBOL_STR(nfs_alloc_fattr) },
	{ 0x7832dda2, __VMLINUX_SYMBOL_STR(make_kgid) },
	{ 0xb606e716, __VMLINUX_SYMBOL_STR(nfs_fattr_init) },
	{ 0xfa7d31bf, __VMLINUX_SYMBOL_STR(xdr_terminate_string) },
	{ 0x654547e7, __VMLINUX_SYMBOL_STR(nfs_setattr) },
	{ 0x4a3a05e7, __VMLINUX_SYMBOL_STR(nfs_fs_type) },
	{ 0x1ae04e2a, __VMLINUX_SYMBOL_STR(from_kuid) },
	{ 0xd2f6220a, __VMLINUX_SYMBOL_STR(rpc_call_sync) },
	{ 0xbfb337a8, __VMLINUX_SYMBOL_STR(rpc_call_start) },
	{ 0x1426513b, __VMLINUX_SYMBOL_STR(register_nfs_version) },
	{ 0x5fc02251, __VMLINUX_SYMBOL_STR(from_kgid) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xc6b4bdc7, __VMLINUX_SYMBOL_STR(nfs_getattr) },
	{ 0x3f404840, __VMLINUX_SYMBOL_STR(nfs_invalidate_atime) },
	{ 0x26884ff7, __VMLINUX_SYMBOL_STR(nfs_alloc_fhandle) },
	{ 0x14679d6c, __VMLINUX_SYMBOL_STR(nfs_lookup) },
	{ 0x7fa09b4c, __VMLINUX_SYMBOL_STR(nfs_rename) },
	{ 0x9f30e4d5, __VMLINUX_SYMBOL_STR(nfs_file_operations) },
	{ 0x16b021c5, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x2dddb57c, __VMLINUX_SYMBOL_STR(make_kuid) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xa1503d10, __VMLINUX_SYMBOL_STR(nfs_mkdir) },
	{ 0x47e9648f, __VMLINUX_SYMBOL_STR(nfs_create) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x5bc35cc6, __VMLINUX_SYMBOL_STR(xdr_read_pages) },
	{ 0xe5919cb1, __VMLINUX_SYMBOL_STR(xdr_encode_opaque) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x52206e19, __VMLINUX_SYMBOL_STR(nfs_init_client) },
	{ 0xb26b5178, __VMLINUX_SYMBOL_STR(nfs_create_server) },
	{ 0xbddee420, __VMLINUX_SYMBOL_STR(nfs_mknod) },
	{ 0xe4cd36fb, __VMLINUX_SYMBOL_STR(nfs_submount) },
	{ 0x9ae83f80, __VMLINUX_SYMBOL_STR(xdr_inline_decode) },
	{ 0xf8351e2e, __VMLINUX_SYMBOL_STR(nfs_wb_all) },
	{ 0x68c7bab0, __VMLINUX_SYMBOL_STR(xdr_write_pages) },
	{ 0x94aa095, __VMLINUX_SYMBOL_STR(nfs_dentry_operations) },
	{ 0x3e8dca4d, __VMLINUX_SYMBOL_STR(nfs_alloc_client) },
	{ 0x8c66d00d, __VMLINUX_SYMBOL_STR(nfs_writeback_update_inode) },
	{ 0xc686bf74, __VMLINUX_SYMBOL_STR(nlmclnt_proc) },
	{ 0xea58e881, __VMLINUX_SYMBOL_STR(nfs_clone_server) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=nfs,sunrpc,lockd";


MODULE_INFO(srcversion, "E896557070AFE372317463B");
