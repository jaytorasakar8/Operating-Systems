
									Home Work 2 - SGFS

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

While deleting a file we rename the file according to the server time. New name of the file in the .sg folder will be "server_timestamp + old_name". Kernel server time source code taken from stack overflow link2  

References: 
1. https://www.thegeekstuff.com/2013/01/mount-umount-examples/
2. For date and time of server - https://stackoverflow.com/questions/5077192/how-to-get-current-hour-time-of-day-in-linux-kernel-space
3. https://elixir.bootlin.com/linux/v2.6.33/source/include/linux/time.h#L163
4. https://stackoverflow.com/questions/2099070/how-can-i-allocate-memory-in-the-linux-kernel-for-a-char-type-string