#include "../fs/sgfs/sgfs_ioctl.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/limits.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char * const argv[])
{
    int rc=0, fd;
    char opt;
    unsigned int flags=0;
    sgfs_ioctl_arg ioctl_arg;
    char *cwd;

    while((opt = getopt(argc, argv, "u")) != -1)
    {
        switch(opt)
        {
            case 'u':
                flags |= 0x01;
                break;
            default:
                return -EINVAL;
        }
    }

    if(flags != 0x01 || argc != 3)
    {
        fprintf(stderr,"Invalid args.\n");
        return -EINVAL;
    }

    if((fd = open(argv[optind],O_RDWR)) == -1)
    {
        fprintf(stderr,"Unable to open %s.\n",argv[optind]);
        return -errno;
    }

    cwd = malloc(PATH_MAX+1);
    memset(cwd,'\0',PATH_MAX+1);

    if(getcwd(cwd,PATH_MAX+1) == NULL)
    {
        fprintf(stderr, "Unable to fetch cwd.\n");
        return -errno;
    }

    ioctl_arg.cwd = cwd;
    ioctl_arg.len = strlen(cwd);

    rc = ioctl(fd, SGUNDEL, &ioctl_arg);

    if(rc)
        printf("File recovery failed: %d.\n",rc);
    else
        printf("File restored successfuly.\n");

    return rc;
}

