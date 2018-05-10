cmd_fs/nfs/nfsv2.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/nfs/nfsv2.ko fs/nfs/nfsv2.o fs/nfs/nfsv2.mod.o
