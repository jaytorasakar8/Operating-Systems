cmd_fs/lockd/lockd.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/lockd/lockd.ko fs/lockd/lockd.o fs/lockd/lockd.mod.o
