/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:19:04 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/09 10:42:03 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*Destination;
	size_t	i;

	i = 0;
	if (!*s)
	{
		Destination = malloc(1);
		if (Destination == NULL)
			return (NULL);
		*Destination = '\0';
		return (Destination);
		// printf("Is the segfault here?....");
	}
	Destination = ((char *)malloc(strlen(s) + 1));
	if (!Destination)
		return (NULL);
	// printf("Is the segfault here?....");
	while (s[i])
	{
		Destination[i] = s[i];
		i++;
		// printf("Is the segfault here?....");
	}
	Destination[i] = '\0';
	return (Destination);
}

int	main(void)
{
	char		*dest = "";
	const char	*string = "If you see me, then I have been copied. :D\n";

	printf(" Original String: %s\n", string);
	printf(" Destintation Then: %s 'empty'\n\n", dest);
	printf("Destination Now:  %s\n", ft_strdup(string));
	return (0);
}
