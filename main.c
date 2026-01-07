#include <stddef.h> //for size_t
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdbool.h>
#include "arena.h"



int main(){

	Arena myArena;

	if(!arena_init(&myArena, 4)){
		printf("creation failed\n");
		return 1;
	}

	printf("My arena base is at %p | capcity is %zu\n", myArena.base, myArena.capacity);

	//allocating a single byte
	char *c = arena_alloc(&myArena, 1);
	*c = 'A';
	printf("allocated char, address is %p, offset is now %zu\n", c, myArena.offset);
	//allocating an integer
	int *i = arena_alloc(&myArena, sizeof(int));
	*i = 42;
	printf("allocated int, address is %p, offset is %zu\n", i, myArena.offset);



	//sure lets allocate a big chunck
	void* blank_space = arena_alloc(&myArena, 2000);
	printf("took up 2000bytes, at address %p, offset is now %zu\n", blank_space, myArena.offset);

	void* way_too_big = arena_alloc(&myArena, 50000); 
	if (way_too_big == NULL) {
    		printf("Arena overflow caught successfully!\n");
	}

	printf("------destroying------\n");
	//I want to look at the pid and stuff
	sleep(30);

	//clean up
	arena_destroy(&myArena);

	printf("Arena Destroyed\n");

	return 0;
}
