cmd_fs/nfs/nfsv3.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/nfs/nfsv3.ko fs/nfs/nfsv3.o fs/nfs/nfsv3.mod.o
