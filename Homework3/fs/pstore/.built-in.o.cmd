cmd_fs/pstore/built-in.o :=  ld -m elf_x86_64   -r -o fs/pstore/built-in.o fs/pstore/pstore.o ; scripts/mod/modpost fs/pstore/built-in.o
