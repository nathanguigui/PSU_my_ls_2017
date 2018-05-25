/*
** EPITECH PROJECT, 2017
** lib_print4.c
** File description:
** 
*/

#include "my_ls.h"

void print_info(char *dir)
{
	struct stat fileStat;
	stat(dir, &fileStat);
	display_nbr_indent(fileStat.st_nlink, 2);
	my_putchar(' ');
	uid_to_user(fileStat.st_uid);
	gid_to_group(fileStat.st_gid);
	display_nbr_indent(fileStat.st_size, 5);
	my_putchar(' ');
}

void print_date(char *dir)
{
	struct stat fileStat;

	stat(dir, &fileStat);
	char *timeoffile = ctime(&fileStat.st_mtime);
	char *tmp = malloc(sizeof(char) * 15);
	int i = 4;
	int k = 0;
	while(k < 14) {
		if(k == 3){
			tmp[k] = '.';
			k = k + 1;
			tmp[k] = ' ';
			k = k + 1;
		}
		tmp[k] = (k == 0) ? timeoffile[i] + 32 : timeoffile[i];
		i = i + 1;
		k = k + 1;
	}
	tmp[k] = '\0';
	my_putstr(tmp);
	my_putchar(' ');
}

void print_list(char *path, char *name)
{
	print_right(path);
	print_info(path);
	print_date(path);
	my_putstr(name);
	my_putchar('\n');
}

void show_total(struct dirent **result, char *path_of_mother)
{
	struct stat fileStat;
	int total = 0;
	int i = 0;
	int temp;
	char *path;

	while(result[i] != NULL) {
		if(result[i]->d_name[0] != '.') {
			path = concat_dir(path_of_mother, result[i]->d_name);
			stat(path, &fileStat);
			temp = (fileStat.st_blocks) * fileStat.st_blksize;
			total = total + temp / 8192;
		}
		i = i + 1;
	}
	my_putstr("total ");
	my_put_nbr(total);
	my_putchar('\n');
}