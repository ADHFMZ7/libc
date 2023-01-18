#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

#define HEAP_SIZE 64000 // defines the size of the heap

//The struct that holds meta data of block
typedef struct metadata
{
	size_t size;										 // the size of the allocated block
	struct metadata *next;					 // A pointer to the next block in the linkedlist
	int free;												 // 
} metadata;

#define META_SIZE sizeof(metadata) // defines size of metadata block

metadata* head = NULL;						 // head of linked list

// Will call sbrk to allocate desired amount of space and create a new metablock with it.
metadata *allocate_space(metadata *prev, size_t size)
{
	// create a new metadata struct	
	metadata block ={.next = NULL, .size = size, .free = 0};

	// set prev blocks next to this block
	prev->next = &block;

	// call sbrk to create block of size + size of metadata
	void *memory = sbrk(META_SIZE + size)	;

	// catch errors thrown by sbrk syscall
	assert(memory != (void *) -1 && "sbrk failed to allocate memory.");

	return memory;
}

metadata *find_free(size_t size)
{

	return NULL;
}


void *myalloc(size_t size)
{
	if (size <= 0)
	{
		return NULL;
	}

	
	// We want to initialize the linked list if it is empty
	if (!head)
	{
		head = allocate_space(NULL, size);

		return head;
	}
	// otherwise, we want to check if there is a free block of the desired size
	else if (find_free(size) != NULL)
	{


		return NULL;
	}
	else {
		//append new allocated space

		return NULL;
	}


}


void myfree(void* location)
{



}
