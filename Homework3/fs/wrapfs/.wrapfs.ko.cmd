cmd_fs/wrapfs/wrapfs.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/wrapfs/wrapfs.ko fs/wrapfs/wrapfs.o fs/wrapfs/wrapfs.mod.o
