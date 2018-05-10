cmd_fs/fscache/fscache.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/fscache/fscache.ko fs/fscache/fscache.o fs/fscache/fscache.mod.o
