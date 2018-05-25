#ifndef MY_LS
#define MY_LS

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

struct parametters
{
	char	l_arg;
	char	R_arg;
	char	d_arg;
	char	r_arg;
	char	t_arg;
};
typedef struct parametters params;

int show_wargument(void *name);
int show_wfolder(char *name);
void show_filename(char *name);
int handle_error();

int handle_errno(void);

int count_item(char *directory_path);
void set_item(char *directory_path, struct dirent **result);

int count_int_digit(int nbr);
int my_strlen(char const *str);
int my_put_long(long int nb);
int my_put_nbr(int nb);

params set_flag(char flag, params para);
params detect_flags(char *flags, params para);
char *str_to_path(char *str);

params detect_params(int ac, char *av[], params para);
params create_params(void);
char *params_to_str(params para);
char *sum_params(int ac, char **ag);

int count_params(int ac, char *av[]);
void multiple_folder(int ac, char *av[], int l);

char *concat_dir(char *path, char *item);
void display_nbr_indent(int nbr, int indent);
void display_str_indent(char *str, int indent);
int count_dirent(struct dirent **result);

long get_date(char *path);
void sort_of_list(struct dirent **result, char *path);
void reverse_list(struct dirent **result);
void noarg_folder_print(char **result);

void noarg_print(struct dirent **result);
void print_right(char *dir);
void uid_to_user(uid_t id);
void gid_to_group(gid_t id);

void print_info(char *dir);
void print_date(char *dir);
void print_list(char *path, char *name);
void show_total(struct dirent **result, char *path_of_mother);

void list_print(struct dirent **result, char *path_of_mother);
void list_dprint(struct dirent **res, char *path_of_mother);
int exec_dprint(struct dirent **result, char *params, char *path_of_mother);
int exec_print(struct dirent **result, char *params, char *path_of_mother);

void	my_putchar();
int	my_putstr(char const *str);
int my_str_isprintable(char const *str);
void impr(char *str);

#endif