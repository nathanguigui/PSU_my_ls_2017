##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	error.c			\
		lib_detect.c		\
		lib_flags.c		\
		lib_params.c		\
		lib_print.c		\
		my_put_nbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_str_isprintable.c


NAME	=	my_ls

CFLAGS	=	-o $(NAME)-include ./include/my_ls.h

all:
	gcc -o $(NAME) *.c

clean:

fclean: clean
	rm -f $(NAME)

re:	fclean all