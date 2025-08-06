# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 19:13:19 by latabagl          #+#    #+#              #
#    Updated: 2025/08/06 22:41:10 by latabagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
HEADER = includes/so_long.h
SRC = src/main.c src/map/map_parser.c src/utils/so_long_utils.c \
	  src/utils/debug.c
SRC_DIR = src
OBJ_DIR = obj
OBJECTS = $(SRC:src/%.c=obj/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
		$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		mkdir -p $(dir $@)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -rf $(OBJECTS) 

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME) 
		
re: clean fclean all
