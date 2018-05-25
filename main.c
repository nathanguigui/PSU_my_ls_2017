/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_ls.h"

void default_item(char *str)
{
	DIR *d;
	d = opendir(".");
	if(d == NULL)
		handle_errno();
	struct dirent *result[count_item(".") + 1];
	set_item(".", result);
	exec_print(result, str, ".");	
}

int detect_item(int ac, char *av[], char *str)
{
	int l = 1;

	while(l != ac) {
		if(my_str_isprintable(av[l]) == 1 && av[l][0] != '-') {
			if(str[2] != '1' && ac - count_params(ac, av) > 1)
				multiple_folder(ac, av, l);
			DIR *d;
			d = opendir(av[l]);
			if(d == NULL)
				handle_errno();
			struct dirent *result[count_item(av[l]) + 1];
			set_item(av[l], result);
			exec_print(result, str, av[l]);
		}
		l = l + 1;
	}
	return(0);
}

int main(int ac, char *ag[])
{
	char *str = sum_params(ac, ag);
	
	if(ac - count_params(ac, ag) == 1)
		default_item(str);
	else
		detect_item(ac, ag, str);
	return(0);
}