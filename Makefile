# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:30:18 by mtrembla          #+#    #+#              #
#    Updated: 2022/07/06 11:00:27 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	srcs/parsing.c \
		srcs/parsing_utils.c \
		srcs/utils.c \

LIB = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRCS:.c-.o)

$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(SRCS) $(LIB)

$(LIB):
			make -C libft/

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make -C libft/ clean

fclean: clean
		$(RM) $(NAME)
		make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus