The FS is the file system folder. It contains the "SGFS" folder which we use. It was deduced from a base filesystem of "wrapfs", which was given to us for working.

SGFS contains the following files: 
1. dentry.c -> Not updated at all
2. file.c -> Code for supporting recovery of deleted files from the .sg folder to the current directory
3. inode.c -> Code for deleting a file from the mount point and moving it to .sg folder
4. Kconfig, lookup.c, nmap.c, super.c -> No updates in these files
5. make_script.sh -> My own script to run the common commands of 

         i) Cleaning and then make
        ii) Mount at a particular point for a particular file system(sgfs here)
       iii) Insert the module 

6. Makefile -> Contains the details on how to build the homework
