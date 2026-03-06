/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 08:13:13 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/16 09:03:17 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
	Allowed functions: write, malloc(optional), free(optional)
	not allowed: printf or other lib helpers
*/

// Printf word in reverse order. Sperated by one space (" " or '\t)

/* e.g

$ ,/rev_words "hello world"
world hello

$./rev_words "  42   Wolfsburg   Piscine   "
Piscine Wolfsburg 42

$./rev_wrods ""
<prints only newline>  */

int	is_space(char *c)
{
	return (c == ' ' || c == '\t')
}
void	print_word(char *str, int start, int end)
{
}

// string length --> check string from back to front --> if space, print word from space ++ to other space or '\0' --> continue until index[0].

char	rev_words(char *str)
{
	size_t	len;
	char	*temp;
	int		i;

	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str != 0)
		{
			if (str == ' ' || str == '\t')
				is_space(str);
			else if (str >= 'a' || str >= 'A' || str <= 'z' || str <= 'Z')
				print_word;
			i++;
		}
		return str;
	}
}
int	main(void)
{
	char	*str;

	str = "Hello World";
	printf("%s\n", rev_words(str));
	return (0);
}

" How do I detect word ending" = "using '\0'";
" Scanning from left-right or right-left?"
	"How do i avoid extra space?"

	1. set tmp value 2. strlen into tmp value 3. loop string &check space 4. if space-- > is_space 5. 3. reverse read from right to left using(-) 4. when



/**/

	int is_space(char c);

void print_word(char *str, int start, int end);

int main(int ac, char **av)
{
    int i;

    if (ac == 2)
    {
        i = length_of_string;

        while (i >= 0)
        {
            // 1 skip spaces
            // 2 find word end
            // 3 find word start
            // 4 print word
            // 5 print space if needed
        }
    }
    write(1, "\n", 1);
}
*/