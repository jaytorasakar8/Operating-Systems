cmd_fs/pstore/ramoops.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/pstore/ramoops.ko fs/pstore/ramoops.o fs/pstore/ramoops.mod.o
