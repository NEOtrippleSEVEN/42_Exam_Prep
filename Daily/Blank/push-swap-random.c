/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap-random.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:57:08 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/04 15:12:44 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Hard code the PUSH, POP, ROTATE etc..
void push(int *src, int *dst, int *top_src, int *top_dst){
	// printf("Before push: %d, %d\n", src, dst);
	if(*top_src < 0)
		return;
	
	(*top_dst)++;
	dst[*top_dst] = src[*top_src];
	(*top_src)--;
	printf("-----------------PUSH EXECUTED-----------------\n");
}

void swap(int *stack, int top)
{
	//printf("Before swap: %d\n", stack);
	if (top < 0)
		return;
	
	int temp;

	temp = stack[top];
	stack[top] = stack[top -1];
	stack[top - 1] = temp;
	printf("-----------------SWAP EXECUTED-----------------\n");
}
int main(){
	
// Program Starts
// Pointers A & B stacks declared() 

int *stack_a;
int *stack_b;
int i = 0;
int random_value;
// Declare size of stack
size_t size = 100;

// Allocate Memory for both stacks 
stack_a = malloc(sizeof(int) * size);
stack_b = malloc(sizeof(int) * size);

// Initialise stack_a with values 
// Initialise stack_b as empty
// Seed random gen once.

srand(time(NULL));
while(i < size){
	random_value = rand() % 100;
	*(stack_a + i) = random_value;
	i++;
}

// Define top index for stack_a 
// Define top inde for stack_b

int top_a = size - 1;		// Last filled element
int top_b = -1;			// Empty Stack 


// Perform Push operation ( A --> B)
// if (top_a >= 0){
	// stack_b++;
	// stack_b[top_b] = stack_a[top_a];
	// stack_a--;
// }
push(stack_a, stack_b, &top_a, &top_b);
swap(stack_a, top_a);
swap(stack_a, top_a);

// Print stacks to verify
printf("Stack A: \n");
for(i = 0; i <= top_a; i++)
	printf("%d ", stack_a[i]);

printf("\n Stack B: \n");
for(i = 0; i <= top_b; i++)
	printf("%d ", stack_b[i]);


printf("\n\n top_a = %d\n", top_a);
printf("top_b = %d\n", top_b);
// Free allocated Memory
stack_a = 0;
free(stack_a);
stack_b = 0;
free(stack_b);

	return 0;
}