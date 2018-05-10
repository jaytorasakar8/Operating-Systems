#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <linux/sched.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/uapi/linux/sched.h"

#define STACK_SIZE 1024*1024

int childFunction(void* filename);

int main(int argc, char** argv)
{
    void *stack,*stackTop;
    char opt;
    unsigned long flags=0;

    while((opt = getopt(argc,argv, "emz")) != -1)
    {
        switch(opt)
        {
            case 'e':
                flags |= CLONE_PROT_ENC;
                break;
            case 'm':
                flags |= CLONE_PROT_MV;
                break;
            case 'z':
                flags |= CLONE_PROT_ZIP;
                break;
            default:
                return -EINVAL;
        }
    }

    if(argc-optind != 1)
    {
        fprintf(stderr,"Invalid args.\n");
        return -EINVAL;
    }

    stack = malloc(STACK_SIZE);
    stackTop = stack + STACK_SIZE;

    clone(childFunction,stackTop,flags,argv[optind]);

    return 0;

}

int childFunction(void* filename)
{
    unlink(filename);

    return 0;
}
