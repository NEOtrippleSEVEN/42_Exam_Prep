/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_Distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 07:32:27 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/02 09:20:09 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Creating a function that calculates the distance between two points.

//(x1, y1) & (x2, y2) === [x1 - x2] + [y1 - y2]

typedef struct s_point{
	int	x;
	int	y;
}		t_point;

int	ft_abs_val(int n){
	if(n < 0)
		return -n;	
	return n;
}

int	ft_point_distance(t_point a, t_point b){

	printf("Distance variables: (%d, %d) and (%d, %d).\n", a.x, b.x, a.y, b.y);
	int distance = ft_abs_val(a.x - b.x) + ft_abs_val(a.y - b.y);
	return distance;
}

int	main(void){

	t_point a;
	t_point b;

	a.x = 20;
	a.y = -15;
	b.x = 18;
	b.y = -5;
	
	printf("The calucalted distance in this case would be the following....\n\n %d Kilometers.\n", ft_point_distance(a,b));
	return 0;
}