# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 17:35:52 by rgatnaou          #+#    #+#              #
#    Updated: 2022/04/23 23:22:26 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
	get_next_line.c \
	utils.c		\
	check_map.c		\
	move.c		\
	atoi.c		\
	split.c
	
HEADER = so_long.h
OBJ = $(SRC:.c=.o) 

FLAGS = -Wall -Wextra -Werror -Imlx

CC = cc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# ex :
# 	./so_long

#bonus :
#

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all