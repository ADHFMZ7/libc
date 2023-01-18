#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include "myalloc.h"

// TODO:
// 1) Implement freeing memory
//	




#define HEAP_SIZE 64000 // defines the size of the heap

#define META_SIZE sizeof(metadata) // defines size of metadata block

metadata* head = NULL;						 // head of linked list

// Will call sbrk to allocate desired amount of space and create a new metablock with it.
metadata *allocate_space(metadata *prev, size_t size)
{
	// create a new metadata struct	
	metadata block ={.next = NULL, .size = size, .free = 0};

	if (prev != NULL){
		// set prev blocks next to this block
		prev->next = &block;
	}

	// call sbrk to create block of size + size of metadata
	void *memory = sbrk(META_SIZE + size)	;

	// catch errors thrown by sbrk syscall
	assert(memory != (void *) -1 && "sbrk failed to allocate memory.");

	return memory;
}

// TODO: fix this depending on how i implement free
// So far returns the final node if no free space is found.
metadata *find_free(size_t size)
{

	metadata *current = head;
	
	while (current)
	{
		if (current->size >= size && current->free) 
		{
			return current;
		}
		current = current->next;
	}
	return current;
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

		return head + META_SIZE;
	}
	else if (find_free(size + META_SIZE))
	{

		return NULL;

	}
	// otherwise, we want to check if there is a free block of the desired size
	else 
	{	
		metadata *current = head;
		while (current->next)	
		{
			current = current->next;
		}

		return (allocate_space(current, size) + META_SIZE);
	}

}


void myfree(void* location)
{



}
