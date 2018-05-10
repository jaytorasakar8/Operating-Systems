cmd_fs/ext4/ext4.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/ext4/ext4.ko fs/ext4/ext4.o fs/ext4/ext4.mod.o
