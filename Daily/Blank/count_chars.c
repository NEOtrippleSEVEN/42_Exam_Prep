/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:54:31 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/18 09:12:28 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// Where is my index? 
// What does it point to?
// Did I move it?

int		count_chars(char *c){
	int i = 0;
	while(c[i])
		i++;
	return i;
}

int		main(){
	char *c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("Character count: 	%d \n", count_chars(c));
	return 0;
}