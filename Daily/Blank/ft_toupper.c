/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 07:50:52 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/10 08:32:14 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	ft_toupper(char c){
	int upper;
	if(c >= 97 || c <= 122){
		upper = c - 32;	
		return upper;
	}
	return 0;
}

int main(){
	char c = 'm';
	printf("from %c to --> %c\n", c, ft_toupper(c));
	return 0;
}