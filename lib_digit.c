/*
** EPITECH PROJECT, 2017
** lib_digit.c
** File description:
** 
*/

#include "my_ls.h"

int count_int_digit(int nbr)
{
	int i = 1;
	int tmp = nbr;

	while(tmp > 9) {
		tmp = tmp / 10;
		i = i + 1;
	}
	return(i);
}

int my_strlen(char const *str)
{
	int i = 0;
	
	while(str[i] != '\0')
		i = i + 1;
	return(i);
}

int my_put_long(long int nb)
{
	long int d;

	if (nb < 0)
	{
		nb = -nb;
		my_putchar('-');
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	d = nb % 10 + 48;
	my_putchar(d);
	return (0);
}

int my_put_nbr(int nb)
{
	int d;

	if(nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if(nb > 9)
		my_put_nbr(nb / 10);
	d = nb % 10 + 48;
	my_putchar(d);
	return (0);
}