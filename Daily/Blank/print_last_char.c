/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_last_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:44:45 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/17 09:42:34 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
	Here we are supposed to print the last char ONLY
	using only WRITE:
*/

char last_char(char *c){
	int i = 0;

	
	// 1, We need to run up the string, save lenght into int len
	if(c[i])
		i++;
	// 2. if len is > 0 then do this 
			// Go to the last char and print only the char. (so whatever char is behind the '\0') 
			//else returns NULL
	//char last; 
	while(c[i] != '\0')
	{
		if(i > 0)
			return(write(1, &i - 1, 1));
		else 
			return (write(1, "<prints newline only>", 22));
		i++;	
	}
	return(*c);		
}


int main()
{
	char *c = "The last character is U.";
	printf("%c\n", last_char(c));


	return 0;
}