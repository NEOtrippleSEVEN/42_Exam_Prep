/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:09:39 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/18 09:25:18 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Fucntion should look like this.. Keep iterating, until spce or special char comes. Then break and return.
void     first_word(char *s)
{
	int i = 0;
	while(s[i] != ' ')
	{
		if(s[i] == ' ')
			break;
		write(1, &s[i], 1);
		i++;
	}
}

int main(){
 
	char *sentence = "Omega-3 The word.";
	first_word(sentence);
	write(1, "\n", 1);
    return 0;
}