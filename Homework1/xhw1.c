#include <asm/unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
#include <unistd.h>
#include "help.h"

#ifndef __NR_xdedup
#error xdedup system call not defined
#endif

int main(int argc, char **argv)
{
   int rc;
//   void *dummy = (void *) argv[1];


//My code here

struct arguments args; //Getting from help.h
args.flags = 0;

//char *filename1 = NULL;
//char *filename2 = NULL;
//char *filename3 = NULL;
//char *buffer= (char*)kmalloc(1024);

 int opt;

 while ((opt = getopt (argc, argv, "npd:")) != -1)
  {
    strcpy(args.ifile1, argv[2]);//Reduce  by -1 from 3 to 2
    strcpy(args.ifile2, argv[3]);//Reduce  by -1
    strcpy(args.ofile, argv[4]);


    switch (opt)
    {
       case 'n':
                 printf("\nCount bytes mode on") ;
                 args.flags = args.flags+1;
                break;

      case 'p':
                printf("\nPartial mode on") ;
                args.flags = args.flags+2;
                break;

      case 'd':
               printf("\nDebug mode on") ;
               args.flags = args.flags+4;
                break;
    }

  }




//////Call to sys_xdedup

   rc = syscall(__NR_xdedup,(void *)&args);
   if (rc == 0)
       printf("syscall returned %d\n", rc);
   else
       printf("syscall returned %d (errno=%d)\n", rc, errno);

   exit(rc);
}

