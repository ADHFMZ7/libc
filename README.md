# libc

This C library reimplements some of the C standard library functions to help myself better understand them.

## TODO:
1. Add free function.
1. Allign allocated memory.

## dynamic allocation (malloc, free) 

My implementation of malloc uses the linked list method to keep track of data. Each block of data that is 
allocated has a small struct that stores metadata about the block. This includes the amount of data it 
holds, a pointer to the next block, and if the block is free or not. 

This gives the malloc function the ability to go through the linked list until a big enough block of free
space is found. It then allocates the memory and appends itself to the linked list. 

The free function can similarly use the provided pointer to remove the block and it's metadata from the 
linked list, allowing malloc to overwrite the block of memory.


## Input/Output

The library implements fgets and puts for simple input and output to the terminal.


### Resources used
- https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
