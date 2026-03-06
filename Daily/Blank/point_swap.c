/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 07:27:40 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/24 08:13:23 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// Program that swaps the values of two 2D points using a struct 

// input: (3, 7) (10, -2)
// ouput: (10, -2) (3, 7)


typedef struct point_swap
{
	int a;
	int b;
	
}point_swap;

void swap(int *a, int *b){
	int *temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){

	point_swap p1;
	point_swap p2;

	p1.a = 3;
	p2.a = 7;
	p1.b = 10;
	p2.b = -2;
	
	printf("Initial Order:  (%d, %d)  (%d, %d) \n\n", p1.a, p2.a, p1.b, p2.b);

	swap(&p1.a, &p1.b);
	swap(&p2.a, &p2.b);

	printf("Swapped Order:  (%d, %d)  (%d, %d) \n\n", p1.a, p2.a, p1.b, p2.b);
	return 0;
}