# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stvalett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 15:05:35 by stvalett          #+#    #+#              #
#    Updated: 2016/11/24 15:45:20 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDE = fillit.h

SRCS = 	checkfile.c\
			init_tetri.c\
			main.c\
			print_map.c\
			solve.c\
			tools.c\
			tools2.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : 
	make -C Libft
	$(CC) $(CFLAG) $(SRCS) Libft/libft.a -I$(INCLUDE) -o $(NAME)

clean :
	make clean -C Libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C Libft
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
