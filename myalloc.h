#ifndef MYALLOC_H
#define MYALLOC_H

#include <stdlib.h>

typedef struct metadata
{
    size_t size;            // the size of the allocated block
    struct metadata *next;  // A pointer to the next block in the linkedlist
    int free;	            // 0/1 if block is free or not
} metadata;

metadata *allocate_space(metadata *prev, size_t size);

metadata* find_free(size_t size);

void *myalloc(size_t size);

void myfree(void* ptr);

#endif
