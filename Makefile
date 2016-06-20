# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 15:52:08 by vgrenier          #+#    #+#              #
#    Updated: 2016/06/11 17:09:25 by vgrenier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I includes/
LIBFLAGS = -L $(LIBDIR) -lft

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/
LIBDIR = ./libft

NAME = ft_ls

SRCNAME = main.c \
		  ft_putfilendl.c \
		  ft_puttotal.c \
		  ft_perm.c \
		  ft_option.c \
		  ft_opendir.c \
		  ft_lstfileadd.c \
		  ft_lstfileaddend.c \
		  ft_readdir.c \
		  ft_lstreadfile.c \
		  ft_lstfiledelone.c \
		  ft_lstfiledel.c \
		  ft_lstfilenew.c \
		  ft_lstargsortal.c \
		  ft_lstargsorttime.c \
		  ft_lstfindtype.c \
		  ft_printdosname.c \
		  ft_lstisdir.c \
		  ft_lstisfile.c \
		  ft_lstishidden.c \
		  ft_recur.c \
		  ft_ls.c \
		  ft_error.c \
		  ft_getfiledetail.c \
		  ft_gettime.c \
		  ft_sizemax.c \
		  ft_compt_lst.c \
		  ft_alsort_arg.c \
		  ft_lst_to_char.c

OBJNAME = $(SRCNAME:.c=.o)

SRC = $(addprefix $(SRCDIR), $(SRCNAME))

OBJ = $(addprefix $(OBJDIR), $(OBJNAME))

.PHONY: all libft clean fclean re

all: libft $(NAME)

libft: submodule
	make -C $(LIBDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFLAGS)

submodule:
	git submodule update --init

clean:
ifneq ($(wildcard "$(LIBDIR)/Makefile"),"")
	make -C $(LIBDIR) clean
else
	git submodule update --init
endif
	rm -rf $(OBJ)

fclean: clean
ifneq ($(wildcard "$(LIBDIR)/Makefile"),"")
	make -C $(LIBDIR) fclean
else
	git submodule update --init
endif
	rm -rf $(NAME)

re: fclean all
