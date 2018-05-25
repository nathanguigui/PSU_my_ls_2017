/*
** EPITECH PROJECT, 2017
** lib_params.c
** File description:
** 
*/

#include "my_ls.h"

params detect_params(int ac, char *av[], params para)
{
	int i = 1;
	while(i != ac) {
		if(av[i][0] == '-')
			para = detect_flags(av[i], para);
		i = i + 1;
	}
	return(para);
}

params create_params(void)
{
	params result;
	result.l_arg = '0';
	result.R_arg = '0';
	result.d_arg = '0';
	result.r_arg = '0';
	result.t_arg = '0';
	return(result);
}

char *params_to_str(params para)
{
	char *result = malloc(sizeof(char) * 6);
	result[0] = para.l_arg;
	result[1] = para.R_arg;
	result[2] = para.d_arg;
	result[3] = para.r_arg;
	result[4] = para.t_arg;
	result[5] = '\0';
	return(result);	
}

char *sum_params(int ac, char **ag)
{
	params para = create_params();
	para = detect_params(ac, ag, para);
	char *str = params_to_str(para);
	return(str);
}