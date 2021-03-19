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

CC = clang
NAME = lib.a
CFLAGS = -Wall -Werror -Wextra
SRCS = argv_to_array.c free_array.c ft_is_all_digit.c \
	push.c reverse_rotate.c rotate.c swap.c check.c

LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a
OBJ = $(SRCS:.c=.o)
 
all: $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) checker.c lib.a -o test

$(NAME): $(OBJ)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJ)

$(LIBFT):
		(cd $(LFT_SRC) && $(MAKE))
clean:
		rm -f $(OBJ) 
		(cd $(LFT_SRC) && $(MAKE) $@)

fclean: clean
		rm -f $(NAME)
		rm -f minishell
		(cd $(LFT_SRC) && $(MAKE) $@)
re: fclean all

.PHONY:all fclean re
