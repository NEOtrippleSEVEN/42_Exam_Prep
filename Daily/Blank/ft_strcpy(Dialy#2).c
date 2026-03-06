/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy(Dialy#2).c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 07:08:51 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/07 14:49:20 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;
	
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while(i < n){
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char *str;
	char dest[50];

	str = "This is the string that is supposed to be copied!";
	printf("%s\n", ft_strcpy(dest, str, 50));
	return (0);
}