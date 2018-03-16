NAME = fillit
SRC = check.c thirdpart.c resolve.c parsing.c
OBJ = check.o thirdpart.o resolve.o parsing.o

all: $(NAME)

$(NAME):
	make -C libft/ re ; make -C libft/ clean
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc $(OBJ) -L./libft/ -lft -o $(NAME)
clean:
	/bin/rm -Rf $(OBJ)
fclean: clean
	/bin/rm -Rf $(NAME)
	/bin/rm -Rf ./libft/libft.a
re: fclean all
