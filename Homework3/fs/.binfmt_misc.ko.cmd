cmd_fs/binfmt_misc.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/binfmt_misc.ko fs/binfmt_misc.o fs/binfmt_misc.mod.o
