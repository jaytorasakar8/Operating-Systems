cmd_fs/quota/built-in.o :=  ld -m elf_x86_64   -r -o fs/quota/built-in.o fs/quota/quota.o fs/quota/kqid.o fs/quota/compat.o ; scripts/mod/modpost fs/quota/built-in.o
