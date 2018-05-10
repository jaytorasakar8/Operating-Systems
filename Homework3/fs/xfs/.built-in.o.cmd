cmd_fs/xfs/built-in.o :=  ld -m elf_x86_64   -r -o fs/xfs/built-in.o fs/xfs/xfs.o ; scripts/mod/modpost fs/xfs/built-in.o
