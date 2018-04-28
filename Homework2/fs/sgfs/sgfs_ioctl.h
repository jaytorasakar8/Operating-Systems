#ifndef SGFS_IOCTL_H
#define SGFS_IOCTL_H
#include <linux/ioctl.h>

typedef struct
{
	char* cwd;
	int len;
} sgfs_ioctl_arg;

#define SGUNDEL _IOR('s', 1, sgfs_ioctl_arg *)

#endif


