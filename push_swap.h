/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:42:53 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/23 03:51:38 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>

# define INT_MINIMUM -2147483648
# define INT_MAXIMUM 2147483647

typedef struct s_stack
{
	struct s_stack	*prev_value;
	int				value;
	int				index;
	int				target_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next_value;
}					t_stack;

typedef struct s_benchmark
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	int				bench;
}					t_benchmark;

typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
}					t_strategy;

long int			ft_atol(const char *str);

//push_swap_error
void				ft_error(void);

// push_swap_adaptive
t_strategy			ft_adaptive_algorithm(t_stack **a, t_benchmark *bench);

// push_swap_bench
char				*ft_strategy_writer(t_strategy strategy);
void				ft_benchmark(float disorder, t_strategy strategy,
						t_benchmark *bench);

// push_swap_complex_algorithm
void				ft_stack_arr_indexing(t_stack **a, int *arr, int size);
int					bit_long(int value);
int					max_bit_long(t_stack **a);
void				bubble_sort(int *arr, int size);
int					*stack_to_arr(t_stack **a);
void				ft_complex_algorithm_helper(t_stack **a, t_stack **b,
						int rotation, t_benchmark *bench);
void				ft_complex_algorithm(t_stack **a, t_benchmark *bench);

void				ft_free_res(char **res);

float				ft_compute_disorder(t_stack **a);

int					ft_check_error(int argc, char *argv[]);

t_stack				*stack_init(int argc, char **argv);

void				med_algo(t_stack **a, t_benchmark *bench);
void				ft_rotate_to_chunk(t_stack **a, int min_idx, int max_idx,
						t_benchmark *bench);
void				ft_rotate_to_target_b(t_stack **b, int target_idx,
						t_benchmark *bench);

void				ft_push_a(t_stack **a, t_stack **b, t_benchmark *bench);
void				ft_push_b(t_stack **a, t_stack **b, t_benchmark *bench);

void				ft_reverse_rotate_a(t_stack **a, t_benchmark *bench);
void				ft_reverse_rotate_b(t_stack **b, t_benchmark *bench);
void				ft_reverse_rotate_a_b(t_stack **a, t_stack **b,
						t_benchmark *bench);

void				ft_rotate_a(t_stack **a, t_benchmark *bench);
void				ft_rotate_b(t_stack **b, t_benchmark *bench);
void				ft_rotate_a_b(t_stack **a, t_stack **b, t_benchmark *bench);

void				ft_three_sorter(t_stack **c, t_benchmark *bench);
void				ft_two_sorter(t_stack **b, t_benchmark *bench);
void				ft_small_sort(t_stack **a, t_benchmark *bench);
void				ft_helper_simple_algorithm(t_stack **a, int size,
						t_benchmark *bench);
void				ft_simple_algorithm(t_stack **a, t_benchmark *bench);

void				ft_stack_clear(t_stack *stack);

void				ft_swap_a(t_stack **a, t_benchmark *bench);
void				ft_swap_b(t_stack **b, t_benchmark *bench);
void				ft_swap_a_b(t_stack **a, t_stack **b, t_benchmark *bench);

t_stack				*ft_new_stack(int new_value);
void				ft_stackadd_front(t_stack **stack, t_stack *node);
t_stack				*ft_stacklast(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *node);
int					ft_stack_size(t_stack **stack);

void				ft_free(char **doublearray);
int					flag_checker(char *arg);
t_stack				*ft_stack_creator(t_stack *a, char *argv[], int argc);
t_stack				*ft_reader(int argc, char *argv[]);

#endif
