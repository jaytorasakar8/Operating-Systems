cmd_fs/nfs_common/grace.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/nfs_common/grace.ko fs/nfs_common/grace.o fs/nfs_common/grace.mod.o
