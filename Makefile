# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2021/03/26 13:05:18 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIB = srcs/libpush.a
NAME1 = push_swap
NAME2 = checker
CFLAGS = -Wall -Werror -Wextra
SRCS = srcs/argv_to_array.c srcs/free_array.c srcs/ft_is_all_digit.c \
	srcs/push.c srcs/reverse_rotate.c srcs/rotate.c srcs/swap.c srcs/check.c \
	srcs/quick_sort.c srcs/checker.c srcs/utils.c srcs/get_set.c \
	srcs/closest_and_move.c srcs/sort_3_5.c

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a
OBJ = $(SRCS:.c=.o)
 
all: $(LIBFT) $(LIB) $(NAME1) $(NAME2)

$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)

$(NAME1): $(LIBFT) $(LIB)
	@$(CC) $(CFLAGS) $(LIB) $(LIBFT) srcs/push_swap.c -o $(NAME1)
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(NAME2): $(LIBFT) $(LIB)
	@$(CC) $(CFLAGS) $(LIB) $(LIBFT) srcs/main_checker.c -o $(NAME2)
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(LIBFT):
	@(cd $(LFT_SRC) && $(MAKE))

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@rm -f $(OBJ) 
	@(cd $(LFT_SRC) && $(MAKE) $@)

fclean:
	@echo "$(RED)deleting both executables and lib...$(NC)"
	@rm -f $(OBJ) $(NAME1) $(NAME2) $(LIB)
	@(cd $(LFT_SRC) && $(MAKE) $@)

re: fclean all

.PHONY:all fclean re
