cmd_fs/mbcache.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/mbcache.ko fs/mbcache.o fs/mbcache.mod.o
