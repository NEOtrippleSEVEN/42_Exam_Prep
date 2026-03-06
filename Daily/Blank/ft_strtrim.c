/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:12:37 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/10 08:41:46 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	in(const char *s1, char c)
{
	while (*s1 && c != *s1)
		s1++;
	return (c == *s1);
}

char get_substring(char *src, char *dest, int start, int len)
{
	for(int i = 0; i < len && src[start+i] != '\0'; i++){
		dest[i] = src[start+i];
	}
	dest[len] = '\0';
	return *dest;
}


char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	end = strlen(s1);
	while (in(set, s1[start]))
		start++;
	while (start >= end)
		return (strdup(""));
	while (in(set, s1[end - 1]))
		end--;
	return (get_substring(s1, set, start, end - start));
}

int	main(void)
{
	const char	*s1 = "      This is the coolest string ever      ";
	const char	*set = " ";

	printf("String 1:  %s\n", s1);
	printf("Trimmed:  %s\n\n", set);
	printf("Final string: %s\n", ft_strtrim(s1, set));
	return (0);
}
