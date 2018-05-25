/*
** EPITECH PROJECT, 2017
** lib_flags.c
** File description:
** 
*/

#include "my_ls.h"

params set_flag(char flag, params para)
{
	switch(flag) {
		case 108:
			para.l_arg = '1';
			break;
		case 82:
			para.R_arg = '1';
			break;
		case 100:
			para.d_arg = '1';
			break;
		case 114:
			para.r_arg = '1';
			break;
		case 116:
			para.t_arg = '1';
			break;
		default:
			handle_error(1, flag);
	}
	return(para);
}

params detect_flags(char *flags, params para)
{
	int i = 1;
	while(flags[i] != '\0') {
		if(flags[i] == '-' && i == 1)
			i = i + 1;
		para = set_flag(flags[i], para);
		i = i + 1;
	}
	return(para);
}

char *str_to_path(char *str)
{
	int i = 0;
	char *tmp = malloc(sizeof(char) * my_strlen(str) + 2);
	while(str[i] != '\0') {
		tmp[i] = str[i];
		i = i + 1;
	}
	if(tmp[my_strlen(str)] != '/')
		tmp[i] = '/';
	return(tmp);
}