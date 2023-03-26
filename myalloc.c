#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "myalloc.h"


// TODO:
// 1) Implement splitting freed memory

#define HEAP_SIZE 64000 // defines the size of the heap

#define META_SIZE sizeof(metadata) // defines size of metadata block

metadata* head = NULL;						 // head of linked list

// Will call sbrk to allocate desired amount of space and create a new metablock with it.
metadata *allocate_space(metadata *prev, size_t size)
{
	// call sbrk to create block of size + size of metadata
	metadata *block = (metadata *) sbrk(META_SIZE + size);

	// set metadata of new block
	block->next = NULL;
	block->size = size;
	block->free = 0;

	if (prev != NULL)
	{
		// set prev blocks next to this block
		prev->next = block;
	}

	// catch errors thrown by sbrk syscall
	assert(block != (void *) -1 && "sbrk failed to allocate memory.");

	return block;
}

// Returns the first free memory block that is the right
// size, otherwise, returns a NULL pointer.
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
		return mem + 1;

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
	
	if (block->next && block->next->free == 1) {
		block->size += block->next->size + META_SIZE;
		block->next = block->next->next;
	}

	block->free = 1;

}



