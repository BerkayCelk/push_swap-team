# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:43:52 by ttezcan           #+#    #+#              #
#    Updated: 2026/04/23 03:13:41 by ttezcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  ft_atol.c push_swap_complex_algorithm.c push_swap_complex_helpers.c push_swap_reverse_rotate.c push_swap_free_res.c push_swap_rotate.c \
main.c push_swap_disorder_metric.c push_swap_simple.c push_swap.c push_swap_error.c \
push_swap_stack_clear.c push_swap_init.c push_swap_swap.c push_swap_adaptive.c push_swap_medium_algorithm.c \
push_swap_medium_helpers.c sort_three_five.c \
push_swap_bench.c push_swap_bench_helpers.c push_swap_push.c push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

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