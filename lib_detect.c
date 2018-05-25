/*
** EPITECH PROJECT, 2017
** lib_detect.c
** File description:
** 
*/

#include "my_ls.h"

int count_item(char *directory_path)
{
	DIR *d;
	d = opendir(directory_path);
	struct dirent *dir;
	int i = 0;
	if(d) {
		while((dir = readdir(d)) != NULL) {
			i = i + 1;
		}
		closedir(d);
	}
	return(i);
}

void set_item(char *directory_path, struct dirent **result)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(directory_path);
	int i = 0;
	if(d) {
		while((dir = readdir(d)) != NULL) {
			result[i] = dir;
			i = i + 1;
		}
		result[i] = '\0';
	}
}