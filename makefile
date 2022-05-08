# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 17:35:52 by rgatnaou          #+#    #+#              #
#    Updated: 2022/04/29 14:45:34 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

SRC = so_long.c 		\
	get_next_line.c \
	utils.c			\
	check_map.c		\
	move.c			\
	itoa.c			\
	split.c
	
SRC_B = bonus/bounus.c 			\
		bonus/get_next_line.c 	\
		bonus/utils.c			\
		bonus/check_map.c		\
		bonus/move_bonus.c		\
		bonus/itoa.c			\
		bonus/split.c			\
		bonus/draw.c			

HEADER = so_long.h

HEADER_B = bonus/so_long_bonus.h

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o) 

FLAGS = -Wall -Wextra -Werror -Imlx

CC = cc

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(HEADER_B) $(OBJ_B)
	$(CC) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all