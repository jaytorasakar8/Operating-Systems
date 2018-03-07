#include <linux/linkage.h>
#include <linux/moduleloader.h>
#include "help.h"
#include <linux/string.h>
//#include <stdio.h>
#include <asm/unistd.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>


int dflag = 0;
asmlinkage extern long (*sysptr)(void *arg);
int read_file(char* filename, char* buf);
int write_file(char* filename, char* data);
void unlink_file(struct file **fileptr);
 void rename_file(struct file **fileptr1, struct file **fileptr2);


asmlinkage long xdedup(void *arg)
{
     struct arguments *args = (struct arguments *) arg;
     int flags = args->flags;


   /* dummy syscall: returns 0 for non null, -EINVAL for NULL */
//   printk("xdedup received arg %p\n", arg);

   if (arg == NULL)
       return -EINVAL;

// First printing to check if args are correctly coming
/*
        printk("\n%s\n", args->ifile1);
        printk("%s\n", args->ifile2);
        printk("%s\n", args->ofile);
        printk("%d\n", flags);
*/


//File names stored in stuct of help.h


if(flags == 0)
      {
          //Logic when no flags are given
          // means that we need to check for direct dedup
        if (args->ifile1 == NULL || args->ifile1 == NULL)
        {
           printk("Files not given");
           return -1;
        }

        else
        {
          char buf1[1024];
          char buf2[1024];
          int bytes1;
           int bytes2;
          char outputfile[1024];
          char oldfile[1024];
          struct file *oldfileptr;
          struct file *newfileptr;

        int error_no = 0;

           struct file *fileptr;
         memset((void*)buf1,0,1024);
         memset((void*)buf2,0,1024);

          bytes1 = read_file(args->ifile1, buf1);
          bytes2 = read_file(args->ifile2, buf2);

          if(bytes1 == bytes2) //Checking if number of bytes are same
          {

         strcpy(outputfile, "temp1.txt");
            strcpy(oldfile, args->ofile);

            oldfileptr = filp_open(oldfile, O_RDONLY | O_WRONLY, 0);
            newfileptr = filp_open(outputfile, O_WRONLY | O_CREAT, 0);
            write_file(outputfile, buf1);



            if(!fileptr)
          {
             error_no = -2;
            return error_no;
          }

                 filp_close(oldfileptr, NULL);
              filp_close(newfileptr, NULL);

              unlink_file(&oldfile);
              rename_file(&outputfile, &oldfile);


              printk("Dedup bytes are: %d", bytes1);
              return bytes1;
          }
          else
          {
            printk("Cannot dedup since files are not same");

          }

        }

      } //end of flag=0




// ------------------------------np flag work here -------------------------------------

else
{
if((flags & 3) == 3)
  {
       //np flag is set
      char buf1[1024];
      char buf2[1024];
      char buf3[1024];

      int count=0;
      int i=0;
      int bytes1 = 0;
      int bytes2 = 0;

      memset((void*)buf1,0,1024);
      memset((void*)buf2,0,1024);
      memset((void*)buf3,0,1024);


      bytes1 = read_file(args->ifile1, buf1);
      bytes2 = read_file(args->ifile2, buf2);

      while(buf1[i] != '\0' || buf2[i] != '\0') //Till the end of file
      {
         if(buf1[i] == buf2[i])
          {
              buf3[count] = buf1[i];
              i++;
              count++;
          }
          else
          {
             break;
          }
       }

       buf3[count] = '\0';
       printk("np flag is active and common thing is : %s", buf3 );

  } // end of np flag


//--------------------n flag starts  here ------------------------------------

   else
  {
      if(flags & 1)
     {
         //flag n is set

      char buf1[1024];
      char buf2[1024];
      int bytes1=0;
      int bytes2=0;

       int match_error = 0;
        int i=0;
        int count=0;

        memset((void*)buf1,0,1024);
         memset((void*)buf2,0,1024);

        bytes1 = read_file(args->ifile1, buf1);
        bytes2 = read_file(args->ifile2, buf2);


       //printk("\n Value of %c", buf1[0]);
       // printk("\nInside if stmt %d %d ", bytes1, bytes2);

  if(bytes1 == bytes2) //Checking if number of bytes are same
         {

          while(buf1[i] != '\0') //Till the end of file
          {
              if(buf1[i] == buf2[i])
              {
                count++;
                i++;
              }
              else
               {
                 match_error = 1; //Means the chars in 2 buffer are not same
                 break;
                }
          }
      }
      else
      {
         printk("\nError: File size not same when n is set");
      }

      if (match_error == 1)
      {
          printk("\nError: File content not same when n is set");
      }
      else
      {
         //Means files have same content
        //Return the size of buf1
        printk("\nSame File size = %d", count-1);
      }

    }//end of n flag

//-----------------------p flag starts here ----------------------------

    if(flags & 2)
    { //flag p is set

      char buf1[1024];
      char buf2[1024];
      char buf3[1024];

      int count=0;
      int i=0;
      int bytes1 = 0;
      int bytes2 = 0;

      memset((void*)buf1,0,1024);
      memset((void*)buf2,0,1024);
      memset((void*)buf3,0,1024);


      bytes1 = read_file(args->ifile1, buf1);
      bytes2 = read_file(args->ifile2, buf2);

      while(buf1[i] != '\0' || buf2[i] != '\0') //Till the end of file
      {
         if(buf1[i] == buf2[i])
          {
              buf3[count] = buf1[i];
              i++;
              count++;
          }
          else
          {
             break;
          }
       }

       buf3[count] = '\0';
       write_file(args->ofile, buf3);

       printk("\nNew updated Common bytes between 2 files : %d", count);

       //---------We need to return the count of bytes which are same in the 2 files i.e. count --
  }//end of p flag


 // ---------------------start of d flag ------------------------------------
 if(flags & 4)
    {
      //flag d is set
      dflag = 1;

      printk("\n Debugging mode enabled. Print 10 msgs");
      printk("\n Debug msg 1");
      printk("\n Debug msg 2");
      printk("\n Debug msg 3");
      printk("\n Debug msg 4");
      printk("\n Debug msg 5");
      printk("\n Debug msg 6");
      printk("\n Debug msg 7");
      printk("\n Debug msg 8");
      printk("\n Debug msg 9");
      printk("\n Debug msg 10");

    }//end of d flag

//--------------------------For wrong combination------------------------------
   else //For errors in combination
    {
         printk("\n Wrong combination of flags given");

    }//end of error combination

}//end of else from np flag

}//end of else from flag = 0

return 0;//Last return of the whole function


}





int read_file(char* filename, char* buf)
{
  //char* filename; //Name of my file
  struct file *filp; //Strcture of file initialized
   int bytes=0;
  mm_segment_t old_fs;
 long long offset = 0;
int size = 1024;

  int error_no;

  if (filename == NULL)
  {
    error_no = -1;
    return error_no;
  }

  old_fs = get_fs();
  set_fs(get_ds());

  filp = filp_open(filename, O_RDONLY, 0);
  if(!filp)
  {
    error_no = -2;
    return error_no;
  }


  bytes = vfs_read(filp, buf, size, &offset );

  set_fs(old_fs);
  filp_close(filp, NULL);


  if(bytes > 0)
    return bytes;
  else
  {
    error_no = -3; //FIle empty
    return error_no;
  }

  return 0; // Doesn't go in the if-else in the worst case

}


int write_file(char* filename, char* data) //if strlen doesn't work then use int size and get size from the calling funct
{
  //char* filename; //Name of my file
  struct file *filp; //Strcture of file initialized
  int bytes=0;
  mm_segment_t old_fs;
  int error_no;
  long long offset = 0;
  int size = 0;

  size = strlen(data);

  if (filename == NULL)
  {
    error_no = -1;
    return error_no;
  }

  old_fs = get_fs();
  set_fs(get_ds());

  filp = filp_open(filename, O_WRONLY|O_CREAT, 0);
  if(!filp)
  {
    error_no = -2;
    return error_no;
  }

  vfs_write(filp, data, size, &offset);

  set_fs(old_fs);
  filp_close(filp, NULL);

 if(bytes > 0)
    return bytes;
  else
  {
    error_no = -3; //
    return error_no;
  }

  return 0;

}//end of write function


 void unlink_file(struct file **fileptr)
  {
    int ret_unlink;
  mm_segment_t oldfs;
  oldfs = get_fs();
  set_fs(get_ds());
  int error_no = 0;

      ret_unlink = vfs_unlink((*fileptr)->f_path.dentry->d_parent->d_inode, (*fileptr)->f_path.dentry, NULL);
     set_fs(oldfs);
     if(ret_unlink )
     {
       error_no = -1;
       printk("Error while unlinking");
     }
     filp_close(fileptr, NULL);

  }

  void rename_file(struct file **fileptr1, struct file **fileptr2)
  {
    int r;
    mm_segment_t oldfs;
  oldfs = get_fs();
  set_fs(get_ds());

    r = vfs_rename (  (*fileptr1)->f_path.dentry->d_parent->d_inode, (*fileptr1)->f_path.dentry,
                  (*fileptr2)->f_path.dentry->d_parent->d_inode, (*fileptr2)->f_path.dentry,
                   NULL,  (*fileptr1)->f_flags);

  set_fs(oldfs);
   filp_close(fileptr1,NULL);
    filp_close(fileptr2, NULL);

  }




static int __init init_sys_xdedup(void)
{
   printk("installed new sys_xdedup module\n");
   if (sysptr == NULL)
       sysptr = xdedup;
   return 0;
}
static void  __exit exit_sys_xdedup(void)
{
   if (sysptr != NULL)
       sysptr = NULL;
   printk("removed sys_xdedup module\n");
}
module_init(init_sys_xdedup);
module_exit(exit_sys_xdedup);
MODULE_LICENSE("GPL");


