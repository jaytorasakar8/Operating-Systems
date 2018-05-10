cmd_fs/dlm/dlm.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o fs/dlm/dlm.ko fs/dlm/dlm.o fs/dlm/dlm.mod.o
