/*
 * Copyright (c) 1998-2015 Erez Zadok
 * Copyright (c) 2009	   Shrikar Archak
 * Copyright (c) 2003-2015 Stony Brook University
 * Copyright (c) 2003-2015 The Research Foundation of SUNY
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */


#include "sgfs_ioctl.h"
#include "sgfs.h"

static ssize_t sgfs_read(struct file *file, char __user *buf,
			   size_t count, loff_t *ppos)
{
	int err;
	struct file *lower_file;
	struct dentry *dentry = file->f_path.dentry;

	lower_file = sgfs_lower_file(file);
	err = vfs_read(lower_file, buf, count, ppos);
	/* update our inode atime upon a successful lower read */
	if (err >= 0)
		fsstack_copy_attr_atime(d_inode(dentry),
					file_inode(lower_file));

	return err;
}

static ssize_t sgfs_write(struct file *file, const char __user *buf,
			    size_t count, loff_t *ppos)
{
	int err;

	struct file *lower_file;
	struct dentry *dentry = file->f_path.dentry;

	lower_file = sgfs_lower_file(file);
	err = vfs_write(lower_file, buf, count, ppos);
	/* update our inode times+sizes upon a successful lower write */
	if (err >= 0) {
		fsstack_copy_inode_size(d_inode(dentry),
					file_inode(lower_file));
		fsstack_copy_attr_times(d_inode(dentry),
					file_inode(lower_file));
	}

	return err;
}

static int sgfs_readdir(struct file *file, struct dir_context *ctx)
{
	//	printk("In SGFS Readdir");
	int err;
	struct file *lower_file = NULL;
	struct dentry *dentry = file->f_path.dentry;

	lower_file = sgfs_lower_file(file);
	err = iterate_dir(lower_file, ctx);
	file->f_pos = lower_file->f_pos;
	if (err >= 0)		/* copy the atime */
		fsstack_copy_attr_atime(d_inode(dentry),
					file_inode(lower_file));
	return err;
}

static long sgfs_unlocked_ioctl(struct file *file, unsigned int cmd,
				  unsigned long arg)
{

   long err = -ENOTTY, in_sg = 0;
	struct file *lower_file;
    struct file *cwd_file;
    struct dentry *dentry = file->f_path.dentry;
    struct dentry *lower_mount_dentry;
    struct dentry *lower_garbage_dentry;
    struct dentry *lower_dir_dentry;
    struct dentry *lower_dentry;
    struct dentry *cwd_dentry;
    struct dentry *lower_new_dentry;
    struct path lower_mount_path, lower_path;
    const struct cred *cred = current_cred();
    sgfs_ioctl_arg ioctl_arg;
    char *cwd,  *restore_filename;    const char *filename;
    const char delim[] = "-";
    struct iattr attr;

	lower_file = sgfs_lower_file(file);
	

 printk("Inside IOCTL method \n");
    
    if(cmd == SGUNDEL)// If ioctl is undelete, handle it 
    {
        // check if file  in .sg 
        lower_dentry = lower_file->f_path.dentry;
        dget(lower_dentry);

        sgfs_get_lower_path(dentry->d_sb->s_root,&lower_mount_path);
        lower_mount_dentry = lower_mount_path.dentry;
        dget(lower_mount_dentry);

        mutex_lock(&lower_mount_dentry->d_inode->i_mutex);
        lower_garbage_dentry = lookup_one_len(".sg",lower_mount_dentry,strlen(".sg"));
        mutex_unlock(&lower_mount_dentry->d_inode->i_mutex);

        // shouldn't ever happen but good to check 
        if(!lower_garbage_dentry || IS_ERR(lower_garbage_dentry))
        {
            err = PTR_ERR(lower_garbage_dentry);
            goto out;
        }

        lower_dir_dentry = lower_dentry;
        while(lower_dir_dentry != lower_mount_dentry)
        {
            if(lower_dir_dentry == lower_garbage_dentry)
            {
                in_sg =1;
                break;
            }

            lower_dir_dentry = lower_dir_dentry->d_parent;
        }
        
        // If target file is not in .sg/ we can't undelete it 
        if(!in_sg)
        {
            err = -EPERM;
            goto out;
        }

        // check that user is file owner before deleting
        if(cred->uid.val != lower_dentry->d_inode->i_uid.val)
        {
            err = -EPERM;
            goto out;
        }

        // get custom ioctl struct from userspace
        if(copy_from_user(&ioctl_arg,(sgfs_ioctl_arg*)arg,sizeof(ioctl_arg)))
        {
            err = -EFAULT;
            goto out;
        }

        // get cwd of caller 
        cwd = (char*)kmalloc(PATH_MAX+1,GFP_KERNEL);
        memset(cwd,'\0',PATH_MAX+1);
        if(copy_from_user(cwd,ioctl_arg.cwd,ioctl_arg.len))
        {
            err = -EFAULT;
            goto free_cwd;
        }
        
        cwd_file = filp_open(cwd,O_DIRECTORY,0);
        
        if(!cwd_file || IS_ERR(cwd_file))
        {
            err = -PTR_ERR(cwd_file);
            goto close_cwd;
        }

        cwd_dentry = cwd_file->f_path.dentry;

        // if cwd is in sgfs get lower_path 
        if(cwd_dentry->d_sb->s_magic == SGFS_SUPER_MAGIC)
        {
            sgfs_get_lower_path(cwd_dentry,&lower_path);
            dput(cwd_dentry);
            cwd_dentry = lower_path.dentry;
        }

        filename = lower_dentry->d_name.name;

        restore_filename = (char*)kmalloc(strlen(filename)+1,GFP_KERNEL);

        if(!strcpy(restore_filename,filename))
            goto free_restore;
        // et original filename (number of seps can be hardcoded because filename format is known) 
        strsep(&restore_filename,delim);
        strsep(&restore_filename,delim);
        strsep(&restore_filename,delim);
        strsep(&restore_filename,delim);

        // get dentry for restored file 
        mutex_lock(&cwd_dentry->d_inode->i_mutex);
        lower_new_dentry = lookup_one_len(restore_filename,cwd_dentry,strlen(restore_filename));
        mutex_unlock(&cwd_dentry->d_inode->i_mutex);

        if(!lower_new_dentry || IS_ERR(lower_new_dentry))
        {
            err = PTR_ERR(lower_new_dentry);
            goto free_restore;
        }

        // setup inode for file 
        err = vfs_create(cwd_dentry->d_inode,lower_new_dentry,dentry->d_inode->i_mode,0);

        if(err)
            goto free_restore;

        // set new file permissions to match deleted file 
        attr.ia_valid = ATTR_MODE | ATTR_UID | ATTR_GID;
        attr.ia_mode = dentry->d_inode->i_mode;
        attr.ia_uid = dentry->d_inode->i_uid;
        attr.ia_gid = dentry->d_inode->i_gid;
        
        inode_lock(d_inode(lower_new_dentry));
        err = notify_change(lower_new_dentry, &attr,NULL);
        inode_unlock(d_inode(lower_new_dentry)); 
        
        if(err)
            goto free_restore;

        lower_dir_dentry = dget_parent(lower_dentry);

        // attempt to move deleted file back to cwd 
        lock_rename(dget_parent(lower_dentry),dget_parent(lower_new_dentry));
        err = vfs_rename(lower_dir_dentry->d_inode,lower_dentry,cwd_dentry->d_inode,lower_new_dentry,NULL,0);
        unlock_rename(dget_parent(lower_dentry),dget_parent(lower_new_dentry));

        if(!err)
            d_drop(dentry);

        goto free_restore;
    }

	//  XXX: use vfs_ioctl if/when VFS exports it 
	if (!lower_file || !lower_file->f_op)
		goto out;
	if (lower_file->f_op->unlocked_ioctl)
		err = lower_file->f_op->unlocked_ioctl(lower_file, cmd, arg);

//	 some ioctls can change inode attributes (EXT2_IOC_SETFLAGS) 
	if (!err)
		fsstack_copy_attr_all(file_inode(file),
 				      file_inode(lower_file));

    goto out;
free_restore:
    kfree(restore_filename);
close_cwd:
    filp_close(cwd_file,NULL);
free_cwd:
    kfree(cwd);
out:
	return err;




/*

	long err = -ENOTTY;
	struct file *lower_file;

	lower_file = sgfs_lower_file(file);

	//  XXX: use vfs_ioctl if/when VFS exports it 
	if (!lower_file || !lower_file->f_op)
		goto out;
	if (lower_file->f_op->unlocked_ioctl)
		err = lower_file->f_op->unlocked_ioctl(lower_file, cmd, arg);

	// some ioctls can change inode attributes (EXT2_IOC_SETFLAGS) 
	if (!err)
		fsstack_copy_attr_all(file_inode(file),
				      file_inode(lower_file));
out:
	return err;
*/


}

#ifdef CONFIG_COMPAT
static long sgfs_compat_ioctl(struct file *file, unsigned int cmd,
				unsigned long arg)
{
	long err = -ENOTTY;
	struct file *lower_file;

	lower_file = sgfs_lower_file(file);

	/* XXX: use vfs_ioctl if/when VFS exports it */
	if (!lower_file || !lower_file->f_op)
		goto out;
	if (lower_file->f_op->compat_ioctl)
		err = lower_file->f_op->compat_ioctl(lower_file, cmd, arg);

out:
	return err;
}
#endif

static int sgfs_mmap(struct file *file, struct vm_area_struct *vma)
{
	int err = 0;
	bool willwrite;
	struct file *lower_file;
	const struct vm_operations_struct *saved_vm_ops = NULL;

	/* this might be deferred to mmap's writepage */
	willwrite = ((vma->vm_flags | VM_SHARED | VM_WRITE) == vma->vm_flags);

	/*
	 * File systems which do not implement ->writepage may use
	 * generic_file_readonly_mmap as their ->mmap op.  If you call
	 * generic_file_readonly_mmap with VM_WRITE, you'd get an -EINVAL.
	 * But we cannot call the lower ->mmap op, so we can't tell that
	 * writeable mappings won't work.  Therefore, our only choice is to
	 * check if the lower file system supports the ->writepage, and if
	 * not, return EINVAL (the same error that
	 * generic_file_readonly_mmap returns in that case).
	 */
	lower_file = sgfs_lower_file(file);
	if (willwrite && !lower_file->f_mapping->a_ops->writepage) {
		err = -EINVAL;
		printk(KERN_ERR "sgfs: lower file system does not "
		       "support writeable mmap\n");
		goto out;
	}

	/*
	 * find and save lower vm_ops.
	 *
	 * XXX: the VFS should have a cleaner way of finding the lower vm_ops
	 */
	if (!SGFS_F(file)->lower_vm_ops) {
		err = lower_file->f_op->mmap(lower_file, vma);
		if (err) {
			printk(KERN_ERR "sgfs: lower mmap failed %d\n", err);
			goto out;
		}
		saved_vm_ops = vma->vm_ops; /* save: came from lower ->mmap */
	}

	/*
	 * Next 3 lines are all I need from generic_file_mmap.  I definitely
	 * don't want its test for ->readpage which returns -ENOEXEC.
	 */
	file_accessed(file);
	vma->vm_ops = &sgfs_vm_ops;

	file->f_mapping->a_ops = &sgfs_aops; /* set our aops */
	if (!SGFS_F(file)->lower_vm_ops) /* save for our ->fault */
		SGFS_F(file)->lower_vm_ops = saved_vm_ops;

out:
	return err;
}

static int sgfs_open(struct inode *inode, struct file *file)
{
	int err = 0;
	struct file *lower_file = NULL;
	struct path lower_path;

//	printk("In SGFS Open");
	/* don't open unhashed/deleted files */
	if (d_unhashed(file->f_path.dentry)) {
		err = -ENOENT;
		goto out_err;
	}

	file->private_data =
		kzalloc(sizeof(struct sgfs_file_info), GFP_KERNEL);
	if (!SGFS_F(file)) {
		err = -ENOMEM;
		goto out_err;
	}

	/* open lower object and link sgfs's file struct to lower's */
	sgfs_get_lower_path(file->f_path.dentry, &lower_path);
	lower_file = dentry_open(&lower_path, file->f_flags, current_cred());
	path_put(&lower_path);
	if (IS_ERR(lower_file)) {
		err = PTR_ERR(lower_file);
		lower_file = sgfs_lower_file(file);
		if (lower_file) {
			sgfs_set_lower_file(file, NULL);
			fput(lower_file); /* fput calls dput for lower_dentry */
		}
	} else {
		sgfs_set_lower_file(file, lower_file);
	}

	if (err)
		kfree(SGFS_F(file));
	else
		fsstack_copy_attr_all(inode, sgfs_lower_inode(inode));
out_err:
	return err;
}

static int sgfs_flush(struct file *file, fl_owner_t id)
{
	int err = 0;
	struct file *lower_file = NULL;

	lower_file = sgfs_lower_file(file);
	if (lower_file && lower_file->f_op && lower_file->f_op->flush) {
		filemap_write_and_wait(file->f_mapping);
		err = lower_file->f_op->flush(lower_file, id);
	}

	return err;
}

/* release all lower object references & free the file info structure */
static int sgfs_file_release(struct inode *inode, struct file *file)
{
	struct file *lower_file;

	lower_file = sgfs_lower_file(file);
	if (lower_file) {
		sgfs_set_lower_file(file, NULL);
		fput(lower_file);
	}

	kfree(SGFS_F(file));
	return 0;
}

static int sgfs_fsync(struct file *file, loff_t start, loff_t end,
			int datasync)
{
	int err;
	struct file *lower_file;
	struct path lower_path;
	struct dentry *dentry = file->f_path.dentry;

	err = __generic_file_fsync(file, start, end, datasync);
	if (err)
		goto out;
	lower_file = sgfs_lower_file(file);
	sgfs_get_lower_path(dentry, &lower_path);
	err = vfs_fsync_range(lower_file, start, end, datasync);
	sgfs_put_lower_path(dentry, &lower_path);
out:
	return err;
}

static int sgfs_fasync(int fd, struct file *file, int flag)
{
	int err = 0;
	struct file *lower_file = NULL;

	lower_file = sgfs_lower_file(file);
	if (lower_file->f_op && lower_file->f_op->fasync)
		err = lower_file->f_op->fasync(fd, lower_file, flag);

	return err;
}

/*
 * sgfs cannot use generic_file_llseek as ->llseek, because it would
 * only set the offset of the upper file.  So we have to implement our
 * own method to set both the upper and lower file offsets
 * consistently.
 */
static loff_t sgfs_file_llseek(struct file *file, loff_t offset, int whence)
{
	int err;
	struct file *lower_file;

	err = generic_file_llseek(file, offset, whence);
	if (err < 0)
		goto out;

	lower_file = sgfs_lower_file(file);
	err = generic_file_llseek(lower_file, offset, whence);

out:
	return err;
}

/*
 * sgfs read_iter, redirect modified iocb to lower read_iter
 */
ssize_t
sgfs_read_iter(struct kiocb *iocb, struct iov_iter *iter)
{
	int err;
	struct file *file = iocb->ki_filp, *lower_file;

	lower_file = sgfs_lower_file(file);
	if (!lower_file->f_op->read_iter) {
		err = -EINVAL;
		goto out;
	}

	get_file(lower_file); /* prevent lower_file from being released */
	iocb->ki_filp = lower_file;
	err = lower_file->f_op->read_iter(iocb, iter);
	iocb->ki_filp = file;
	fput(lower_file);
	/* update upper inode atime as needed */
	if (err >= 0 || err == -EIOCBQUEUED)
		fsstack_copy_attr_atime(d_inode(file->f_path.dentry),
					file_inode(lower_file));
out:
	return err;
}

/*
 * sgfs write_iter, redirect modified iocb to lower write_iter
 */
ssize_t
sgfs_write_iter(struct kiocb *iocb, struct iov_iter *iter)
{
	int err;
	struct file *file = iocb->ki_filp, *lower_file;

	lower_file = sgfs_lower_file(file);
	if (!lower_file->f_op->write_iter) {
		err = -EINVAL;
		goto out;
	}

	get_file(lower_file); /* prevent lower_file from being released */
	iocb->ki_filp = lower_file;
	err = lower_file->f_op->write_iter(iocb, iter);
	iocb->ki_filp = file;
	fput(lower_file);
	/* update upper inode times/sizes as needed */
	if (err >= 0 || err == -EIOCBQUEUED) {
		fsstack_copy_inode_size(d_inode(file->f_path.dentry),
					file_inode(lower_file));
		fsstack_copy_attr_times(d_inode(file->f_path.dentry),
					file_inode(lower_file));
	}
out:
	return err;
}

const struct file_operations sgfs_main_fops = {
	.llseek		= generic_file_llseek,
	.read		= sgfs_read,
	.write		= sgfs_write,
	.unlocked_ioctl	= sgfs_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl	= sgfs_compat_ioctl,
#endif
	.mmap		= sgfs_mmap,
	.open		= sgfs_open,
	.flush		= sgfs_flush,
	.release	= sgfs_file_release,
	.fsync		= sgfs_fsync,
	.fasync		= sgfs_fasync,
	.read_iter	= sgfs_read_iter,
	.write_iter	= sgfs_write_iter,
};

/* trimmed directory options */
const struct file_operations sgfs_dir_fops = {
	.llseek		= sgfs_file_llseek,
	.read		= generic_read_dir,
	.iterate	= sgfs_readdir,
	.unlocked_ioctl	= sgfs_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl	= sgfs_compat_ioctl,
#endif
	.open		= sgfs_open,
	.release	= sgfs_file_release,
	.flush		= sgfs_flush,
	.fsync		= sgfs_fsync,
	.fasync		= sgfs_fasync,
};
