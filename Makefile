NAME = ft_ls

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib
	clang -Wall -Wextra -Werror -I libft/ -o $(OBJ) -c $(SRC);
	clang -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I libft/ -L libft/ -lft;
	rm -f $(OBJ);

lib:
	make -C libft/ re && make -C libft/ clean;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
