# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 15:52:08 by vgrenier          #+#    #+#              #
#    Updated: 2016/04/20 17:51:25 by vgrenier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LST = liblst/ft_lstreadfile.c \
	  liblst/ft_lstreaddir.c \
	  liblst/ft_lstaffichdos.c \
	  liblst/ft_lstfileadd.c \
	  liblst/ft_lstfileaddend.c \
	  liblst/ft_lstfilenew.c \
	  liblst/ft_lstfilesortal.c


SRC = main.c \
	  ft_opendir.c \
	  ft_option.c

OBJ = main.o \
	  ft_lstreadfile.o \
	  ft_lstreaddir.o \
	  ft_lstaffichdos.o \
	  ft_lstfileadd.o \
	  ft_lstfileaddend.o \
	  ft_lstfilenew.o \
	  ft_lstfilesortal.o \
	  ft_opendir.o \
	  ft_option.o

HEAD = includes/

all: $(NAME)

$(NAME): lib
	gcc -Wall -Wextra -Werror -c $(SRC) $(LST) -I $(HEAD)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I $(HEAD) -L libft/ -lft;
	rm -f $(OBJ);

lib:
	make -C libft/;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
