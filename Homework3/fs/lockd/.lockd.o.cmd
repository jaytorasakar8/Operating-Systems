cmd_fs/lockd/lockd.o := ld -m elf_x86_64   -r -o fs/lockd/lockd.o fs/lockd/clntlock.o fs/lockd/clntproc.o fs/lockd/clntxdr.o fs/lockd/host.o fs/lockd/svc.o fs/lockd/svclock.o fs/lockd/svcshare.o fs/lockd/svcproc.o fs/lockd/svcsubs.o fs/lockd/mon.o fs/lockd/xdr.o fs/lockd/clnt4xdr.o fs/lockd/xdr4.o fs/lockd/svc4proc.o fs/lockd/procfs.o ; scripts/mod/modpost fs/lockd/lockd.o