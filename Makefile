# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 23:41:01 by fsanches          #+#    #+#              #
#    Updated: 2022/07/25 23:44:45 by fsanches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC_PATH = ./src

LIBFT_PATH = ./libft
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

HEADERS = ./headers/so_long.h
INCLUDES_DIR = ./headers $(LIBFT_PATH)
INCLUDES = $(addprefix -I,$(INCLUDES_DIR))

SRCS	= main.c ft_pipex.c get_commands.c clear.c utils.c pipex_utils.c

OBJS = $(SRCS:%.c=%.o)
SRCS	:= $(addprefix $(SRC_PATH)/,$(SRCS))


.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS)

clean: 
	rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -r $(NAME)
	make fclean -C ./libft

valgrind:
	valgrind --leak-check=full -s --show-leak-kinds=all --trace-children=yes ./$(NAME) infile "cat" "wc -l" outfile

re: fclean all
