
             Operating Systems : Homework 2 - Secure Garbage File System

--------------------------------------------------------------------------------------------------------------

We are trying to make a Secure Garbage File system.
Our starting point was of the assignment was to modify the already given wrapfs files present in /fs/wrapfs directory
We started by copying the given wrapfs folder into the /fs/ directory and renaming the new file system as sgfs

In Unix, when you delete/unlink a file, it is deleted permanently. New OSs nowadays offer a "trash" or "garbage" icon, so when you delete a file, it's not deleted right away, but instead is moved to the trash. Later on, you can purge your deleted files manually.

SGFS is intended to create such a secure garbage folder. When a user deletes a file, the file should instead be moved to a special "hidden" folder called ".sg/" at the top of the mount point. A folder is hidden if it's directory name starts with a . ("dot") 

We also insert modules before mounting at appropriate mount point. 

For mounting, we use the following syntax :  mount -t type device destination_dir

I have used the following syntax in order to mount the file system
				mount -t sgfs /dev/ /mnt/sgfs/

This will mount the SGFS file system in the /dev/ folder
Once mounted, we will get a .sg folder inside the mount point.
This .sg folder will act as a Garbage folder, where files which are deleted are moved into

So whenever we delete any file, we will move that file to .sg folder present at our mount point.
While deleting a file we rename the file according to the current time at which the file in being deleted. New name of the file in the .sg folder will be "Timestamp + old_name".

For example, if you a delete a file named a.txt on April 1,2018 at 13:00:00, then the file in the trash folder, will be renamed and stored as 2018-01-04-13-00-00-a.txt, and the contents should be stored in an encrypted format(not supported by my code)

The code also supports file recovery options as well. The deleted file currently in the trash bin, will be moved back to the current working directory, if the command is given. Command to restore the file to current working directory	
				   cd /usr/src/hw2-jtorasakar/hw2
	compile using: gcc -o sgctl sgctl.c
	run as: ./sgctl -u /mnt/sgfs/.sg/<filename to be recovered>

This will move the file from trash bin to the the current working directory(to ../hw2/ directory), with all it's contents. The data should be decrypted(not supported by me). The file is moved from trash bin to current working directory.


[Kernel server time source code taken from stack overflow link2]


Limitations: 
1. Encryption and decryption functionality not supported when the file is being moved from current folder to trash bin and trash bin to current working directory respectively.
2. "ls" command not supported (If we have non authorized user trying to access the trash folder, then we should not allow the other user to access the files in the trash folder)


References: 
1. https://www.thegeekstuff.com/2013/01/mount-umount-examples/
2. For date and time of server - https://stackoverflow.com/questions/5077192/how-to-get-current-hour-time-of-day-in-linux-kernel-space
3. https://elixir.bootlin.com/linux/v2.6.33/source/include/linux/time.h#L163
4. https://stackoverflow.com/questions/2099070/how-can-i-allocate-memory-in-the-linux-kernel-for-a-char-type-string
5. https://elixir.bootlin.com/linux/v4.6/source/net/ceph/crypto.c#L3
