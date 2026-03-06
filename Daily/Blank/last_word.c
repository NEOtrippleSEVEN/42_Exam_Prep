/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:19:11 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/20 13:52:02 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Print only last word of the string.
int is_space(char c){
	return (c == ' ' || c == '\t' || c == '\n');
}

void	last_word(char *s){

	int i = 0;
	int end;

	while(s[i]) i++;
	i--;
	while( i >= 0 && is_space(s[i]))
		i--;
	end = i;
	while(i >= 0 && !is_space(s[i]))
		i--;
	while(++i <= end)
		write(1, &s[i], 1);
}

int main(){
	
	char *string = "This is the string, any last words?";
	last_word(string);
	
	return 0;
}