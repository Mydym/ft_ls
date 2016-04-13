NAME = ft_ls

SRC = main.c \
	  ft_strreadfile.c \
	  ft_strreaddir.c \
	  ft_opendir.c \
	  ft_straffichdos.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib
	clang -Wall -Wextra -Werror -c $(SRC) -I includes/
	clang -Wall -Wextra -Werror -o $(NAME) $(SRC) -I includes/ -L libft/ -lft;
	rm -f $(OBJ);

lib:
	make -C libft/ re && make -C libft/ clean;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
