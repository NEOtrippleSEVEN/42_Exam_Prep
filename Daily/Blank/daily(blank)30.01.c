/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily(blank)30.01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:38:14 by kmurched          #+#    #+#             */
/*   Updated: 2026/01/30 14:58:50 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int	main(void)
{
	int results = ft_strlen("abc");
	printf("String length: %d\n", results);
	return (0);
}
