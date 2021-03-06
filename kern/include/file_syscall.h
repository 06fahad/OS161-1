
#ifndef _FILE_DESCRIPTOR_H
#define _FILE_DESCRIPTOR_H

struct filehandle{
	char filename[NAME_MAX];	//file name, name size set to max size
	int flags;			//flags to indicate previlages
	off_t offset;			//file offset
	int refcnt;			//to keep a count on the number of 
	struct lock* lock;		//for synchronizing access to file descriptors
	struct vnode* vn;		//representation of a file
};

int
sys_open(userptr_t , int, int*);

int
sys_close(int);

int
sys_write(int, userptr_t , size_t, int *);

int
sys_read(int, userptr_t , userptr_t, int *);


int
sys_dup2(int, int , int*);

int
sys_chdir(userptr_t);

int
sys__getcwd(userptr_t, size_t);


int
sys_lseek(int, off_t *, int);

int
sys_remove(userptr_t);

#endif
