#include <stdlib.h>

size_t size = sizeof(size_t) + sizeof(void*) + sizeof(int);

//The struct that holds meta data of block
struct metadata
{
	size_t size;
	struct metadata *next;
	int free;
};



void *malloc(size_t size)
{


	return NULL;	
}

void free(void* location)
{



}


int main()
{

	

}
