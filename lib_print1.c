/*
** EPITECH PROJECT, 2017
** lib_print1.c
** File description:
** 
*/

#include "my_ls.h"

char *concat_dir(char *path, char *item)
{
	int len_path = my_strlen(path);
	int len_item = my_strlen(item);
	char *result = malloc(sizeof(char) * (len_path + len_item + 2));
	int i = 0;
	int k = 0;
	while(path[i] != 0) {
		result[k] = path[i];
		i = i + 1;
		k = k + 1;
	}
	if(path[i - 1] != '/') {
		result[k] = '/';
		k = k + 1;
	}
	i = 0;
	while(item[i] != 0) {
		result[k] = item[i];
		i = i + 1;
		k = k + 1;
	}
	result[k] = '\0';
	return(result);
}

void display_nbr_indent(int nbr, int indent)
{
	int i = 0;

	if((indent - count_int_digit(nbr)) < 0)
		my_put_nbr(nbr);
	else {
		while(i != (indent - count_int_digit(nbr))) {
			my_putchar(' ');
			i = i + 1;
		}
		my_put_nbr(nbr);
	}
}

void display_str_indent(char *str, int indent)
{
	int i = 0;

	if((indent - my_strlen(str)) < 0)
		my_putstr(str);
	else {
		my_putstr(str);
		while(i != (indent - my_strlen(str))) {
			my_putchar(' ');
			i = i + 1;
		}
	}
}

int count_dirent(struct dirent **result)
{
	int i = 0;
	while(result[i] != NULL)
		i = i + 1;
	return(i);
}