                                 Operating Systems Homework 3 - Asynchronous Queuing

Submitted By: 
1. Rishab Chhabra - 109622927
2. Jay Torasakar - 111406252

----------------------------------------------------------------------------------------------------

Steps to compile and run the commands and flags:
 - cd /usr/src/hw3-cse506g20 and make the kernel
 - cd /usr/src/hw3-cse506g20 and do make modules
 - Then do, make modules_install install


Details and Design: 

When we delete a file, we are actually unlinking the file and moving it to the trash bin. Before the unlinking and moving to the trash bin, the user can ask to compress or encrypt or just move the file to the trashbin. So we are handling 3 flags in order to know which command the user has provided us with:
1. CLONE_PROT_MV : When this flag is set, we just move the unlinked file to the trash folder
2. CLONE_PROT_ZIP : When this flag is set, we move the unlinked files to the trash folder after compressing them. 
3. CLONE_PROT_ENC : When this flag is set, we move the unlinked files to the trash folder after encrypting them. 

The user could also provide multiple flags when we are trying to move the file to the trashbin. So all the cases have been handled according to the user requirements. 

For the encryption we have use Block Cipher Encryption technique. In that, we read data in form of blocks or chunks of a specified buffer size, and then we encrypt that data using the Block cipher algorithm. We add a data padding at the end of the text(if needed), when the data size is not of the required size(as needed for the block cipher algorithm). For a large file, we call the file multiple times, dividing the given file into chunks of smaller sizes, and then encrypting them one by one.  

For the compression we have used LZ4 compression algorithm technique. We read the data from the given file and then compress it using LZ4 compression algorithm. The compression algorithm is reducing the file size upto 50% in case of large files. 

We need to protect the trashbin folder from multiple users. Basically we have made a global trashbin folder. But the files inside, are dependent on the user who is unlinking the files. When an file is unlinked, and it is moved to the trash folder, we are renaming the file according the user(uid) and  who has unlinked the file. So incase of multiple files being deleted, then we can easily differentiate between the files present based on their time stamp. For example, if the "root" user is unlinking the file named "a.txt", the new file name after moving to trashbin is "uid-timestamp-a.txt".   

This assignment also talks about asynchronously managing the queues for file operations. For small files we are deleteing the files synchronously. For larger files we are moving the files in asynchronous manner. When we are moving large files, we are moving the files asynchronously, by creating a new kernel queue. The queue length is set to a maximum length of 10. 

For undeleting a file from the trashbin, we move the given file back to the original location by uncompressing it, if needed. For getting the original location from where the file came from, we are using the iprivate data of the file. Using the iprivate struct, we know where the file originated from and we can restore the file back at that position. We are successfully able to move the file from the trash folder to the original location. We are able to decrypt and uncompress the file


Limitations:

1. No support both encrypt and compress flags together 
2. We don't support displaying the whole queue which is being processed by the user


References: 
1. For encryption and decryption part: We have used Block Cipher for encryption and decryption of data. Source code taken from :
https://elixir.bootlin.com/linux/v4.6/source/net/ceph/crypto.c#L83 and
https://github.com/atomic-penguin/linux/blob/1ea6b8f48918282bdca0b32a34095504ee65bab5/net/ceph/crypto.c and
https://stackoverflow.com/questions/9363347/encryption-and-decryption-using-aes-in-linux-kernel


2. For compression and decompression: We have used LZ4 compression algorithm. Source code taken from: 
https://github.com/lz4/lz4  and
https://github.com/lz4/lz4/tree/dev/examples


3. For reading of /proc fs, we referenced code from: 
https://linux.die.net/lkmpg/x710.html  and
https://linux.die.net/lkmpg/x769.html  and 
http://tuxthink.blogspot.com/2017/03/creating-proc-read-and-write-entry.html

4. Clone reference: http://man7.org/linux/man-pages/man2/clone.2.html

5. For file rename to current timestamp: https://stackoverflow.com/questions/5077192/how-to-get-current-hour-time-of-day-in-linux-kernel-space

6. Checkpatch checked using: http://prabhakarlad.blogspot.com/2014/03/checkpatch-from-linux.html and
https://stackoverflow.com/questions/82726/convert-dos-line-endings-to-linux-line-endings-in-vim




