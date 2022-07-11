# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:30:18 by mtrembla          #+#    #+#              #
#    Updated: 2022/07/11 14:20:43 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	parsing.c \
		parsing_utils.c \
		utils.c \
		main.c \
		move.c \

LIB = make -C ./libft
MLX = make -C ./minilibx
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGl -framework AppKit
RM = rm -f
OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(LIB)
			$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx/libmlx.a $(MLXFLAGS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make -C libft/ clean

fclean: clean
		$(RM) $(NAME)
		make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus