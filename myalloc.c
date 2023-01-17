#include <stdlib.h>

#define HEAP_SIZE 64000 // 

size_t size = sizeof(size_t) + sizeof(void*) + sizeof(int);

//The struct that holds meta data of block
struct metadata
{
	size_t size;
	struct metadata *next;
	int free;
};


void *myalloc(size_t size)
{


	return NULL;	
}


void myfree(void* location)
{



}


