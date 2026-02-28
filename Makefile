# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:43:52 by ttezcan           #+#    #+#              #
#    Updated: 2026/02/28 10:22:05 by ttezcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunused

SRCS = push_swap_push.c push_swap_reverse_rotate.c push_swap_rotate.c push_swap_swap.c push_swap_utils.c 

OBJS = $(SRCS:.c=.o)



all: $(NAME)
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re