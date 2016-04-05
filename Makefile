NAME = ft_ls

SRC =

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib
	gcc -Wall -Wextra -Werror -o $(OBJ) -c $(SRC);
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ);

lib:
	make -C libft/ && make -C libft/ clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
