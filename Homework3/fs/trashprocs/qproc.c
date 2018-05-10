#include <linux/module.h> 
#include <linux/kernel.h> 
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

#define FILENAME "queue_capacity"

size_t file_size =  32;
int len = 0, last_read = 0;
struct proc_dir_entry *queue_capacity;
struct file_operations fops;
char* file_data;

ssize_t proc_read(struct file *filp,char *buf,size_t count,loff_t *offp ) 
{
    int res;

    memset(buf,'\0',count);

    if(count > len)
        count = len;

    if(count - last_read == 0)
    {
        count = last_read = 0;
    }
    else
    {
        res = copy_to_user(buf,file_data,count);
        if(res < 0)
        {
            count = res;
            last_read = 0;
        }
        else
        {
            last_read = count;
        }
    }

    return count;
}

ssize_t proc_write(struct file *filp,const char *buf,size_t count,loff_t *offp)
{
    int res;

    if(count >= file_size-1)
        count = file_size-2;    

    memset(file_data,'\0',file_size);
    res = copy_from_user(file_data,buf,count);
    
    if(!res)
        len = count;
    else
        len = count = 0;

    return count;
}


static int __init mymodule_init (void) 
{ 
    fops.read = proc_read;
    fops.write = proc_write;

    queue_capacity = proc_create(FILENAME, 0,NULL,&fops);
        
    if (queue_capacity == NULL) 
    {
        remove_proc_entry(FILENAME,NULL);
        printk(KERN_ALERT "Error: Could not initialize proc file\n");
        return -ENOMEM;
    }

    file_data = (char*)kmalloc(file_size*sizeof(char),GFP_KERNEL);

    snprintf(file_data,strlen("10")+1,"10");

    len = 3; 

    printk("Module initialized successfully.%s\n",file_data);
    return 0; 
} 


static void __exit mymodule_exit (void) 
{ 
    remove_proc_entry(FILENAME,NULL);
    kfree(file_data);
    printk("Module un initialized successfully \n");  
} 


MODULE_AUTHOR("Rishab C");
MODULE_LICENSE("GPL");

module_init(mymodule_init); 
module_exit(mymodule_exit); 

