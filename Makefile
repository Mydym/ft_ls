# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 15:52:08 by vgrenier          #+#    #+#              #
#    Updated: 2016/05/26 16:55:05 by vgrenier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I includes/
LIBFLAGS = -L $(LIBDIR) -lft

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/
LIBDIR = ./lib/libft/

NAME = ft_ls

SRCNAME = main.c \
		  ft_putfilendl.c \
		  ft_puttotal.c \
		  ft_perm.c \
		  ft_option.c \
		  ft_opendir.c \
		  ft_lstfileadd.c \
		  ft_lstfileaddend.c \
		  ft_lstreadfile.c \
		  ft_lstfiledelone.c \
		  ft_lstfilenew.c \
		  ft_lstargsortal.c \
		  ft_lstargsorttime.c \
		  ft_convertsectonsec.c \
		  ft_lstfindtype.c \
		  ft_printdosname.c \
		  ft_lstisdir.c \
		  ft_lstishidden.c \
		  ft_recur.c \
		  ft_ls.c \
		  ft_badname.c \
		  ft_intlen.c \
		  ft_getfiledetail.c \
		  ft_gettime.c \
		  ft_sizemax.c \
		  ft_lst_to_char.c

OBJNAME = $(SRCNAME:.c=.o)

SRC = $(addprefix $(SRCDIR), $(SRCNAME))

OBJ = $(addprefix $(OBJDIR), $(OBJNAME))

.PHONY: all clean fclean re

all: libft $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFLAGS)

libft:
	make -C $(LIBDIR)

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re: fclean all
