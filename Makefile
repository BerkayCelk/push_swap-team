# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:43:52 by ttezcan           #+#    #+#              #
#    Updated: 2026/04/08 21:06:10 by ttezcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunused

SRCS =  ft_atol.c push_swap_complex_algorithm.c push_swap_reverse_rotate.c push_swap_control_form.c push_swap_rotate.c \
main.c push_swap_disorder_metric.c push_swap_simple.c push_swap.c push_swap_error.c \
push_swap_stack_clear.c push_swap_init.c push_swap_swap.c push_swap_adaptive.c push_swap_medium_algorithm.c \
push_swap_debug.c \
push_swap_bench.c push_swap_push.c push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re