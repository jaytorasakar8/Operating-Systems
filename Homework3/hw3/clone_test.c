#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/uapi/linux/sched.h"

#define STACK_SIZE 1024*1024

int childFunction();

int main()
{
    void *stack,*stackTop;

    stack = malloc(STACK_SIZE);
    stackTop = stack + STACK_SIZE;

    clone(childFunction,stackTop,CLONE_PROT_ZIP|CLONE_PROT_ENC|CLONE_PROT_MV,0);

    return 0;

}

int childFunction()
{
    printf("Just a test function for now.\n");

    unlink("./test.txt");

    return 0;
}
