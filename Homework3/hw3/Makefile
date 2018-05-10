all: clone_test cloned_rm trashctl

trashctl: trashctl.c
	gcc -Wall trashctl.c -o trashctl

clone_test: clone_test.c
	gcc -Wall clone_test.c -o clone_test

cloned_rm: cloned_rm.c
	gcc -Wall cloned_rm.c -o cloned_rm

clean: 
	-rm -f clone_test cloned_rm; true
