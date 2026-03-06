/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_Start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:06:34 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/02 18:15:16 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node 
{
	struct s_node *next;
	int value;
	
} t_node;

typedef struct s_stack
{
	t_node *top;				// Index of top element
	t_node *bottom;
	int size;					// Max capacity 
} t_stack;

t_node *ft_new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if( node == NULL)
		return NULL;
		
	node->next = NULL;
	node->value = value;
	return node;
};
void ft_free_node(t_node *node)
{
	if(node == NULL)
		return;
	free(node);	
}


void ft_stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack-> bottom = NULL;
	stack->size = 0;
}
void ft_stack_push(t_stack *stack, int value){
	// Create a new node 
	t_node *node = ft_new_node(value);
	
	if(!node)
		return;
	
	/* Emoty Stack */
	if( stack->top == NULL)
	{
		// Handle the case where stack already has the code in it. 
		node-> next = NULL;
		stack-> top = node; 
		stack-> bottom = node; 
	} else{
		// Update Top, Bottom, Size.
		node->next = stack->top;
		stack-> top = node;
	}
	stack->size++;
}

int ft_stack_pop(t_stack *stack){

	if (!stack || !stack->top)
		return -1;
	
	//save value of top;
	int value = stack->top->value;
	//save the next pointer;
	t_node *next = stack->top->next;
	
	// free the top node 
	ft_free_node(stack->top);
	// Update top into = value so you can return it.
	stack->top = next;
	
	stack->size--;

	if (stack->size == 0)
		stack->bottom = NULL;   
	return value;	
}

void	ft_print_stack(t_stack *stack)
{
	t_node *current = stack->top;
	while(current != NULL){
		printf("Value: %d \n", current->value);
		current = current->next;
	}
}


int main()
{
	// Declare and init two stacks 

	t_stack stack_a;
	t_stack stack_b;

	ft_stack_init(&stack_a);
	ft_stack_init(&stack_b);

	// Push a few Hardcoded values onto stack_a
	ft_stack_push(&stack_a, 1);
	ft_stack_push(&stack_a, 32);
	ft_stack_push(&stack_a, 11);
	ft_stack_push(&stack_a, 2);
	ft_stack_push(&stack_a, 30);
	ft_stack_push(&stack_a, 110);
	
	// Print stack_a to verify
	t_node *current = stack_a.top;
	ft_print_stack(&stack_a);
	
	// Pop a value and print it to verify
	int popped = ft_stack_pop(&stack_a);
	printf("Popped value: %d\n", popped);
	ft_print_stack(&stack_a);
	
	return 0;
}