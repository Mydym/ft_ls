# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 15:52:08 by vgrenier          #+#    #+#              #
#    Updated: 2016/04/25 17:49:54 by vgrenier         ###   ########.fr        #
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
		  ft_option.c \
		  ft_opendir.c \
		  ft_filestat.c \
		  ft_lstaffichdos.c \
		  ft_lstfileadd.c \
		  ft_lstfileaddend.c \
		  ft_lstfiledel.c \
		  ft_lstfiledelone.c \
		  ft_lstfiledelend.c \
		  ft_lstfilenew.c \
		  ft_lstfilesortal.c \
		  ft_lstargsortal.c \
		  ft_lstreaddir.c \
		  ft_lstreadfile.c \
		  ft_lstreadarg.c \
		  ft_lstfindtype.c \
		  ft_lstcheckarg.c \
		  ft_lstafficharg.c \
		  ft_printdosname.c \
		  ft_verifaffich.c \
		  ft_lstisdir.c \
		  ft_lstisfile.c \
		  ft_lstishidden.c \
		  ft_recur1.c \
		  ft_badname.c

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
