NAME = ft_ls

LST = liblst/ft_lstreadfile.c \
	  liblst/ft_lstreaddir.c \
	  liblst/ft_lstaffichdos.c \
	  liblst/ft_lstfileadd.c \
	  liblst/ft_lstfilenew.c \


SRC = main.c \
	  ft_opendir.c

OBJ = main.o \
	  ft_lstreadfile.o \
	  ft_lstreaddir.o \
	  ft_lstaffichdos.o \
	  ft_lstfileadd.o \
	  ft_lstfilenew.o \
	  ft_opendir.o

HEAD = includes/


all: $(NAME)

$(NAME): lib
	clang -Wall -Wextra -Werror -c $(SRC) $(LST) -I $(HEAD)
	clang -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I $(HEAD) -L libft/ -lft;
	rm -f $(OBJ);

lib:
	make -C libft/ re && make -C libft/ clean;

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
