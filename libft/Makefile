# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2019/10/22 15:55:51 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror 
SRCS = ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c \
ft_strnstr.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c \
ft_strrchr.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c \
ft_tolower.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c \
ft_toupper.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
get_next_line.c get_next_line_utils.c
OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
bonus: all $(OBJ_B)
		ar rc $(NAME) $(OBJ_B)
clean:
		rm -f $(OBJ) $(OBJ_B)
fclean: clean
		rm -f $(NAME)
re: fclean all
