*This has been created for the general understanding of dynamic memeoyr allocation in C programming language which is also a part of my 42 learning *


## Goals 
1. Understand that ```malloc``` and ```free``` allocate and de-allocate memory from the heap. 
2. Use dynamic memory to build a linked list. 

## Dynamic Memory Allocation 

C doesn't support dynamically allocating new things in memory. Which is why ```malloc()``` is used to allocate a new chunk of memory from the heap segment. 

#### malloc() ==> Allocates memory and return pointer to the memory. Memory is yet not initialised.
< Example: ```p = malloc(n)``` - allocates ```n``` bytes of heap memory>

#### calloc() ==> does the same with the difference of initialising memory. 
< Exmaple: 'p = calloc(count, size)' allocates 'count*size' bytes to heap memory initialised to all zeros. 
			this is appropriate when you want to allocate an array of 'count' items, each of 'size' bytes
>

#### Free() ==> free is used to deallocate or free up the space allocated by the functions (malloc, calloc, realloc). It takes only one argument 
< Example: 	```free(p)``` - where 'p' is a pointer to heap memory - releases that portion of heap memory for future use. >

#### heap ==> Is a type of tree data structure where each node is either >, = or < than the values of it's 'children'. !
[alt text](max-heap-1.webp)

### additional funcion:

#### realloc() ==> 	Resizes a previously allocated memory block (via malloc/calloc) to a new size. Existing content stay 						preserved potentially re allocating location in memory, else NULL if all fails. 
< Example: 		```p = realloc(p, n)``` - where ```p``` is a pointer to heap memory, expands (or shrinks) its allocation to ```n``` bytes>

## Memory Leaks & Stray Points
### ground rule: For every ```malloc()``` there must be a matching ```free()``` ! 

> If you allocate space but never free it, memory leaks are created. As the program runs the process memory size will keep growing. Inevitably running you out of memory. 

> Heap corruption is also possible if we try to free(never allocated pointer) or double free(). This corruptes the heap's data structures and triggers seg faults in the future - mostly random time. 

Hence the ground rule of >pairing up< ```malloc()``` with ```free()``` always! 

! ! Good practice: 	Always after freeing a pointer ```free(p)``` set the value of the pointer to NULL ```p = NULL``` just in case to prevent reusing. So apon accidential reuse, you know where the seg fault is coming from. 


### Writing Functional Memory allocation

> Avoid sprinkling function calls yet instead focus on the kinds of things you need to create/destroy and write type-specific wrapper for each such type. 

### Example Code:
```C
struct listnode *listnode_new(...);

void listnode_free(struct listnode *node);
```
- The first function calls ``` malloc(sizeof(struct listnode))``` and initalizes all of it's contents, perhaps using parameters passed by the caller. 
- The ```new``` function acts like a 'constructor' in object-oriented languages and can ensure the newly returned memory initializedor atleast not random bytes
- 

> For Clarification on 'Code wrappers'
> Defintion: 	Code wrappers are programming components such as functions, claasses, or libraries that "wrap" around exisiting code to simplify, modify, or standardize it's interface, often enhancing usability or compatibility. 
> Use Cases: 	This helps programmers to use complex, legacy or foreign code without changing the original, or facility tasks like API interaction, data handling, and cross-language innteroperability.   

Example: 
```C
1. Structure Definition

struct listnode {
	char *name;		// Data (a name string)
	struct listnode *next;	// Pointer to next node
};

2. Wrapper for creation (listnode_new):

struct listnode *listnode_new(char *name)
{
	// Here's the malloc, allocating space for one node.
	struct listnode *node = malloc(sizeof(struct listnode));

	if( node == NULL){
		return NULL 	// Error Handling: Malloc failed (e.g out of memory)
	} else{
		// Initialize to avoid random garbage values
		node->next = NULL;
		node->name = name;
	}
	return node;
}
```
^^ This is called the Higher-level fucntions like ```list_insert()```. It handles allocation and setup in one spot.If more mallocs needed for futher fields, there is where they should be added. 

>Now remember the Ground rule? 
The wrapper for destruction (```listnode_delete```, which is like ```listnode_free```);

```C
void listnode_delete(struct listnode *node){
	if(node != NULL){
		if(node->name != NULL)
			free(node-->name);	// Free any sub-allocated memory (the name string)
		free(node);				// Here's the free! Releases the node itself. 
	}
}
```
- This used when removing duplicates in ```main()```. It ensures safe cleanup, freeing any nested allocations first
in ```main()```, you don't see ```malloc()``` or ```free()``` directly:

```C
int main(){
	
	struct listnode head = {NULL, NULL};	// Dummy head node (no Malloc needed yet)
	
	while(!feof(stdin)) {
		char *name = readlinep();			// Assume this allocates the name string
		if(name != NULL)
			list_insert(&head, name);		// Calls listnode_new internally. No direct malloc here
	}

	// Duplicate removal loop 
	for(struct listnode *node = head.next; node != NULL;){
		if(node->next != NULL && strcmp(node->name, node->next->name) == 0){
			struct listnode *duplicate = node->next;
			node->next = node->next->next;
			listnode_delte(duplicate);		// Calls free internally. No direct free here. 
		} else {
			node = node->next;
		}
	}
// Here your printing logic would come in.
}
``` 
With this approach, we focus on the things that matter (Inserting, checking dups, and printing). The memory details are abstracted away.

### Tips for learning Dynamic Memory with the above style 

- **Start Simple**: Practive writing your own wrappers for a basic struct. For exmaple, create a ```struct person {char *name; int age;}``` then add ```person_new(char *name, int age)``` with ```malloc``` inside. and ```person_free(struct person *p)``` with ```free``` inside. 

- **Error Checking**: This is key so always check if ```malloc()``` returns NULL. in wrappers you can add consistent handling (e.g print an error and exit).

- **Avoid Memory Leak**: For every ```Malloc()```, ensure a matrching ```free()```. wrappers help because you pair every ```_new``` call with a ```_free``` later. 

- **Remember.. Valgrind is your friends**: Use it to detect leaks. here's how ```Firstly compile``` then use the following in the terminal ``` $valgrind --leak-check=yes --log-file=valgrind.rpt a.out```. 

- **Why this matters for linked lists?**: Lists often need multiple allocations (one allocation per node, plus maybe for data like strings). Wrappers make growing/shrinking the list safer and less error-prone.



# What are wrappers really? 

> Definition: Wrappers are dedicated functions that encapusalte (or "wrap") low-level operations like memory allocation (```malloc```) and deallocation (```free```) for a specific data type.

> They handle initialization, error checking, and cleanup in one place, making your main code cleaner, more readable, and less error-prone. This abstracts away repetitive details. 

### Example 1 without wrappers (Direct malloc/free)
Here's a simple linked list node insertion without wrappers. ```malloc()``` and ```free()``` are sprinkled directly in the logic, which can get messy if repeated often:
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listnode {
	char *name;
	struct listnode *next;
};

int main(){
	struct listnode *head = NULL;

	// Allocate and intialize a new node directly 
	struct listnode *newn_node = malloc(sizeof(struct listnode));
	if(new_node == NULL){
		fprintf(stderr, "Malloc Failed\n");	// stderr is a standard error message that is used to print output on the screen
		return 1;
	}
	new_node->name = strdup("Alice");		// Assume strdup allocates the string
	new_node->next = head;
	head = new_node;

	// Use the list...

	// Free directly (must remember to free sub-Allocations too)
	while (head != NULL){
		strcut listnode *temp = head;
		head = head-> next;
		free(temp->name); 					// Free the string first
		free(temp);
	}
	return 0;
}
```
- Issues: Error Checking and initialization are inline, repeated if you add more nodes. Easy to forget freeing nested allocation (like ```name```).

### Example 2 - with wrappers

Now, the same logic but with wrappers (```listnode_new``` and ```listnode_free```). The main code focuses on high-level operations, while wrappers isolate the memory details:

```C 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listnode {
	char *name;
	struct listnode *next;
};

// Wrapper for allocation and initialization !! 
struct listnode *listnode_new(const char *name){
	struct listnode *node = malloc(sizeof(struct listnode));
	if(node == NULL){
		fprintf(stderr, "Malloc Failed Horribly\n");
		return 0;
	}
	node -> next = strdup(name);		// Allocates and copies the string
	node -> next = NULL;
	return node;
}

// Wrapper for deallocation 
void listnode_free(struct listnode *node) {
	if (node != NULL) {
		free(node -> name); 		// Hanldes nested free
		free(node);
	}
}

int main(){
	struct listnode *head = NULL;

	// Clean: Just call the wrapper
	struct listnode *new_node = listnode_new("Alice");
	if(new_node == NULL){
		return 1;
	}
	new_node -> next = head;
	head = new_node;

	// Use the list... 

	// Free using the wrapper (recursive or loops for full list)
	while ( head != NULL) {
		struct listnode *temp = head;
		head = head->next;
		listnode_free(temp);
	}
	return 0;
}
```

Benefits of such an appraoch is centralized easier to find, debug, add features or handle complex types with mutliple allocations.

