/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** 
*/

#include "my_ls.h"

int show_wargument(void *name)
{
	my_putstr("my_ls: invalid option -- '");
	my_putchar(name);
	my_putstr("'\nTry « my_ls -help » for more information.\n");
	exit(84);
}

int show_wfolder(char *name)
{
	my_putstr("my_ls: cannot access directory '");
	my_putstr(name);
	my_putstr("': there are no file or folder of this type");
	exit(84);
}

void show_filename(char *name)
{
	my_putstr(name);
}

int handle_error(int error, void *name)
{
	switch(error) {
		case 1:
			show_wargument(name);
			break;
		case 2:
			show_wfolder(name);
			break;
		case 3:
			show_filename(name);
	}
	return(84);
}