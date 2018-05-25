/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** 
*/

#include "my_ls.h"

void	my_putchar(void *c)
{
	write (1, &c, 1);
}

int	my_putstr(char const *str)
{
	int c = 0;

	while(str[c] != '\0') {
		my_putchar(str[c]);
		c = c + 1;
	}
	return (0);
}

int my_str_isprintable(char const *str)
{
	int i = 0;

	while(str[i] != '\0') {
		if(!(str[i] >= 32 && str[i] <= 126))
			return(0);
		i = i + 1;
	}
	return(1);
}

void impr(char *str)
{
	my_putstr(str);
	my_putchar('\n');
}