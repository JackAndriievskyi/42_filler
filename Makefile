#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yandriie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 15:16:58 by yandriie          #+#    #+#              #
#    Updated: 2018/08/01 09:00:46 by yandriie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = yandriie.filler

SRC_FILES = filler.c set_player.c set_map.c set_figure.c place_valid.c count_adv.c
SRC_PATH = sources/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_PATH = objectives/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

HDR_FILES = filler.h
HDR_PATH = includes/
HDR = $(addprefix $(HDR_PATH), $(HDR_FILES))

LIB_NAME = libft.a
LIB_PATH = libft/
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HDR_PATH)

all: $(OBJ_PATH) $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -fdR $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(LIB)
	/bin/rm -f $(NAME)

re: fclean all