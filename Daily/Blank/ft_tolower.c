/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:32:18 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/10 08:40:54 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		ft_islower(char c){
	int lower;
	if(c >= 64 || c <= 90){
		lower = c + 32;
		return lower;
	}
	return  0;
}

int main(){
	char c = 'A';
	printf("Watch the originail character ( %c ) turn into lower case... BAM! ( %C )\n\n\n\n\n\n\n\n\n I told you, now pay up..\n", c, ft_islower(c));
	return 0;
}