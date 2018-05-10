cmd_fs/jbd2/jbd2.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/jbd2/jbd2.ko fs/jbd2/jbd2.o fs/jbd2/jbd2.mod.o
