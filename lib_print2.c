/*
** EPITECH PROJECT, 2017
** lib_print2.c
** File description:
** 
*/

#include "my_ls.h"

long get_date(char *path)
{
	struct stat fileStat;

	stat(path, &fileStat);
	long time_result = fileStat.st_ctim.tv_sec;
	return(time_result);
}

void sort_of_list(struct dirent **result, char *path)
{
	struct dirent *temp_dirent;
	int i = 0;
	int n = count_dirent(result);

	for (i = n; i != 0; i = i - 1) {
		for (int j = 1; j != i; j = j + 1) {
			if(get_date(concat_dir(path, result[j - 1]->d_name)) < 
				get_date(concat_dir(path, result[j]->d_name))) {
				temp_dirent = result[j - 1];
				result[j - 1] = result[j];
				result[j] = temp_dirent;
			}
		}
	}
}

void reverse_list(struct dirent **result)
{
	struct dirent *temp;
	int i = 0;
	int l = 0;

	while (result[l] != NULL) {
		l = l + 1;
	}
	l = l - 1;
	while (i < l) {
		temp = result[i];
		result[i] = result[l];
		result[l] = temp;
		i = i + 1;
		l = l - 1;
	}
}

void noarg_folder_print(char **result)
{
	int k = 0;
	while(result[k][0] != '\0') {
		my_putstr(result[k]);
	}
}