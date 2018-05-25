/*
** EPITECH PROJECT, 2017
** lib_print3.c
** File description:
** 
*/

#include "my_ls.h"

void noarg_print(struct dirent **result)
{
	int k = 0;
	while(result[k] != NULL) {
		(result[k]->d_name[0] != '.') ?
		impr(result[k]->d_name) : 1;
		k = k + 1;
	}
}

void print_right(char *dir)
{
	struct stat fileStat;
	stat(dir, &fileStat);
	my_putchar((S_ISDIR(fileStat.st_mode)) ? 'd' : '-');
	my_putchar((fileStat.st_mode & S_IRUSR) ? 'r' : '-');
	my_putchar((fileStat.st_mode & S_IWUSR) ? 'w' : '-');
	my_putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
	my_putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
	my_putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
	my_putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
	my_putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
	my_putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
	my_putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
	my_putchar(' ');
}

void uid_to_user(uid_t id)
{
	struct passwd *pwd;

	pwd = getpwuid(id);
	if(pwd)
		display_str_indent(pwd->pw_name, 6);
	my_putchar(' ');
}

void gid_to_group(gid_t id)
{
	struct group *grp;

	grp = getgrgid(id);
		display_str_indent(grp->gr_name, 6);
	my_putchar(' ');
}