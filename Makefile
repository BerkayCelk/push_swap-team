# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:43:52 by ttezcan           #+#    #+#              #
#    Updated: 2026/03/12 17:23:42 by ttezcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunused

SRCS = push_swap_push.c push_swap_reverse_rotate.c push_swap_rotate.c push_swap_swap.c push_swap_utils.c \
		push_swap_disorder_metric.c push_swap_simple.c push_swap.c push_swap_complex_algorithm.c

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