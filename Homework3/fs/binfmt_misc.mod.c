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
	{ 0xe405be1d, __VMLINUX_SYMBOL_STR(kill_litter_super) },
	{ 0x6dad7cb, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0xde12acd8, __VMLINUX_SYMBOL_STR(default_llseek) },
	{ 0x3200e84e, __VMLINUX_SYMBOL_STR(simple_statfs) },
	{ 0xf9bb7591, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x8c64aba7, __VMLINUX_SYMBOL_STR(unregister_binfmt) },
	{ 0xddff5736, __VMLINUX_SYMBOL_STR(__register_binfmt) },
	{ 0xa3788a93, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x4ff9f67a, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x3df14bba, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0xb48de4fe, __VMLINUX_SYMBOL_STR(simple_pin_fs) },
	{ 0x55fab2b9, __VMLINUX_SYMBOL_STR(current_fs_time) },
	{ 0xe953b21f, __VMLINUX_SYMBOL_STR(get_next_ino) },
	{ 0xa4defd19, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0x4b857a12, __VMLINUX_SYMBOL_STR(lookup_one_len) },
	{ 0x64bbc288, __VMLINUX_SYMBOL_STR(string_unescape) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x5d8532ee, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x65ad8a27, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x555f6938, __VMLINUX_SYMBOL_STR(lockref_get) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xd45cc6ca, __VMLINUX_SYMBOL_STR(bin2hex) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0x619cb7dd, __VMLINUX_SYMBOL_STR(simple_read_from_buffer) },
	{ 0xb808626e, __VMLINUX_SYMBOL_STR(simple_release_fs) },
	{ 0x5fd2035d, __VMLINUX_SYMBOL_STR(dput) },
	{ 0xa3e52ec8, __VMLINUX_SYMBOL_STR(d_drop) },
	{ 0x8cf3354b, __VMLINUX_SYMBOL_STR(drop_nlink) },
	{ 0xe8db8dd2, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0xb5419b40, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x10fc3465, __VMLINUX_SYMBOL_STR(clear_inode) },
	{ 0x30055d7b, __VMLINUX_SYMBOL_STR(simple_fill_super) },
	{ 0xd6a81681, __VMLINUX_SYMBOL_STR(mount_single) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x825f91e4, __VMLINUX_SYMBOL_STR(prepare_binprm) },
	{ 0x97a9d7c5, __VMLINUX_SYMBOL_STR(would_dump) },
	{ 0x1eb76c26, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0xa843805a, __VMLINUX_SYMBOL_STR(get_unused_fd_flags) },
	{ 0x7198b0a3, __VMLINUX_SYMBOL_STR(remove_arg_zero) },
	{ 0xdcb0349b, __VMLINUX_SYMBOL_STR(sys_close) },
	{ 0xe8e88f00, __VMLINUX_SYMBOL_STR(search_binary_handler) },
	{ 0x2b2f852c, __VMLINUX_SYMBOL_STR(kernel_read) },
	{ 0xae7c9f43, __VMLINUX_SYMBOL_STR(open_exec) },
	{ 0x50bb4c33, __VMLINUX_SYMBOL_STR(bprm_change_interp) },
	{ 0x66608481, __VMLINUX_SYMBOL_STR(copy_strings_kernel) },
	{ 0xd6a036c3, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x9f984513, __VMLINUX_SYMBOL_STR(strrchr) },
	{ 0x179651ac, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "12A1E794B5CFE84EBE229BC");
