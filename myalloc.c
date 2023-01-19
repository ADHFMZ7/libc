#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "myalloc.h"


// TODO:
// 1) Implement freeing memory
// 2) 

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
	metadata *memory = sbrk(META_SIZE + size)	;

	// catch errors thrown by sbrk syscall
	assert(memory != (void *) -1 && "sbrk failed to allocate memory.");

	*memory = block;	

	return memory;
}

// Returns the first free memory block that is the right
// size, otherwise, returns a NULL pointer.
// TODO: implement splitting free block.
metadata *find_free(size_t size)
{

	metadata *current = head;
	
	while (current)
	{
		if (current->size >= size && current->free) 
		{
			printf("found freed block with address %p\n", current+1);
			return current;
		}
		current = current->next;
	}
	return NULL;
}


void *myalloc(size_t size)
{
	
	if (size <= 0)
	{
		return NULL;
	}
	metadata *mem;

	// We want to initialize the linked list if it is empty
	if (!head)
	{

		head = allocate_space(NULL, size);

		return head + 1;
	}
	else if ((mem = find_free(size)))
	{
		printf("allocating memory in freed bloack %p\n", mem+1);
		return mem;

	}
	// otherwise, we want to check if there is a free block of the desired size
	else 
	{	
		metadata *current = head;
		while (current->next)	
		{
			current = current->next;
		}

		return allocate_space(current, size) + 1;
	}

}


void myfree(void* ptr)
{
	// This should mark the block of memory as free,
	// allowing it to be overwritten.
	
	metadata* block = ((metadata *)ptr) - 1;

	block->free = 1;

}



