/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:06:54 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/11 13:18:29 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int makeNegative(const int num)
{
  int *i = 0;
  
  while(num){
    if(num[i] == '-' || num[i] != '\0' && num > '0'){
      i++;
      printf("%d\n", num[i]);
    }
    else if(num != '\0' && i > 0 && num[i] != '-'){
      i++;
      printf("-%d\n", num);
    }
    else if(num == '0')
      return 0;
    i++;
  }
  return num;
}

int main(){

	int num = 5;
	printf("%d\n", makeNegative(num));
	return 0;
}