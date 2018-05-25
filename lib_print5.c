/*
** EPITECH PROJECT, 2017
** lib_print5.c
** File description:
** 
*/

#include "my_ls.h"

void list_print(struct dirent **result, char *path_of_mother)
{
	int k = 0;

	show_total(result, path_of_mother);
	while(result[k] != NULL) {
		char *str = concat_dir(path_of_mother, result[k]->d_name);
		(result[k]->d_name[0] != '.') ?
		print_list(str, result[k]->d_name) : 1;
		k = k + 1;
	}
}

void list_dprint(struct dirent **res, char *path_of_mother)
{
	int k = 0;
	while(res[k] != NULL) {
		char *str = concat_dir(path_of_mother, res[k]->d_name);
		if(res[k]->d_name[0] == '.' && res[k]->d_name[1] == '\0') {
			print_list(str, path_of_mother);
			break;
		}
		k = k + 1;
	}
}

int exec_dprint(struct dirent **result, char *params, char *path_of_mother)
{

	if(params[0] == '1') {
		list_dprint(result, path_of_mother);
		return(0);
	}else
		my_putstr(path_of_mother);
	return(0);

}

int exec_print(struct dirent **result, char *params, char *path_of_mother)
{
	if(params[4] == '1')
		sort_of_list(result, path_of_mother);
	if(params[3] == '1')
		reverse_list(result);
	if(params[2] == '1') {
		exec_dprint(result, params, path_of_mother);
		return(0);
	}
	if(params[0] == '1')
		list_print(result, path_of_mother);
	else
		noarg_print(result);
	return(0);
}