#include "../fs/ioctl.h"
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

    rc = ioctl(fd, TRASHUNDEL, NULL);

    if(rc)
        printf("File recovery failed: %d.\n",rc);
    else
        printf("File restored successfuly.\n");

    return rc;
}
