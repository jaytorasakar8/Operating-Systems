#ifndef IOCTL_H
#define IOCTL_H

#define TRASHUNDEL _IO('s', 1)

int vfs_true_unlink(struct inode* dir,struct dentry *dentry, struct inode **delegated_inode);

#endif
