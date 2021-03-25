# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2020/12/01 12:37:07 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = lib.a
CFLAGS = #-Wall -Werror -Wextra
SRCS = srcs/argv_to_array.c srcs/free_array.c srcs/ft_is_all_digit.c \
	srcs/push.c srcs/reverse_rotate.c srcs/rotate.c srcs/swap.c srcs/check.c \
	srcs/quick_sort.c srcs/checker.c srcs/utils.c srcs/get_set.c \
	srcs/closest_and_move.c srcs/sort_3_5.c

LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a
OBJ = $(SRCS:.c=.o)
 
all: $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) srcs/main_checker.c lib.a -o checker
	$(CC) $(CFLAGS) push_swap.c lib.a -o push_swap

$(NAME): $(OBJ)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJ)

$(LIBFT):
		(cd $(LFT_SRC) && $(MAKE))
clean:
		rm -f $(OBJ) 
		(cd $(LFT_SRC) && $(MAKE) $@)
fclean:
		rm -f $(OBJ)
		rm -f $(NAME)
		rm -f checker
		rm -f push_swap
		(cd $(LFT_SRC) && $(MAKE) $@)
re: fclean all

.PHONY:all fclean re
