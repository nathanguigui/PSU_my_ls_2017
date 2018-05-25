/*
** EPITECH PROJECT, 2017
** lib_params2.c
** File description:
** 
*/

#include "my_ls.h"

int count_params(int ac, char *av[])
{
	int i = 1;
	int k = 0;
	while(i != ac) {
		if(av[i][0] == '-')
			k = k + 1;
		i = i + 1;
	}
	return(k);
}

void multiple_folder(int ac, char *av[], int l)
{
	if(ac > 2 + count_params(ac, av)) {
		l > 1 ? my_putchar('\n') : 1;
		my_putstr(av[l]);
		my_putstr(":\n");
	}
}