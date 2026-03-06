/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:00:26 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/07 14:46:17 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_isalpha(int c)
{
	if (c <= 65 || c >= 90)
	{
		printf(" Characters is an upper case Alpha.. Congrats!!\n");
		return (c);
	}
	else if (c <= 122 || c >= 97)
	{
		printf("The Character is a lowercase Alphabet..Congrats!!!\n");
		return (c);
	}
	else
	{
		printf(" Character is not Alpha...sorry");
		return (0);
	}
	return (c);
}

int	main(void)
{
	int c = 'A';
	printf("mhhm what is c?...\n");
	printf("Let's test.. \n %c\n", ft_isalpha(c));

	return (0);
}