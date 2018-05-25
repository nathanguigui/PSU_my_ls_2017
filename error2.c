/*
** EPITECH PROJECT, 2017
** error2.c
** File description:
** 
*/

#include "my_ls.h"

int handle_errno(void)
{
	my_putstr(strerror(errno));
	my_putchar('\n');
	exit(84);
}