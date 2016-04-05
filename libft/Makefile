# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 20:15:57 by vgrenier          #+#    #+#              #
#    Updated: 2016/01/08 16:30:47 by vgrenier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find ./ -type f | grep ".c$$" | grep -vE "(/\.|main\.c)")

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) ; ar rc $(NAME) $(OBJ) ; ranlib $(NAME)

test: all
	gcc -Wall -Werror -Wextra main.c -L. -lft
	
clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
