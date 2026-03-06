/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detecting_word_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:17:58 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/20 08:18:01 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		count_word(char *sen){
	int i = 0;
	int count = 0;
	//size_t word_count;
	
	//int len = strlen(sen + 1);
	
	while(sen[i] != '\0'){
		//printf("#1  count: %d, index:  %d\n", count, i);
		if(sen[i] == ' '){
			//printf("#2  count: %d, index:  %d\n", count, i);
			count += 1;
			i++;
		}
		//printf("#3  count: %d, index:  %d\n", count, i);
		i++;
	}
	//printf("#4  count: %d, index:  %d\n", count, i);
	return count;
}

// return WORD count.

// index until space is found. 
// onces found, count +1 and continue. 
int main(){
	char *s = "This is the sentence.";
	count_word(s);
	printf("%d \n", s);
	return 0;
}


// LEN = strlen 
// i = indexing string 
// count = word count