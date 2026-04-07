/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:42:53 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/07 21:22:52 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
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
}					t_benchmark;

typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
}					t_strategy;

//push_swap_error
void				ft_error(void);

// push_swap_adaptive
t_strategy			ft_adaptive_algorithm(t_stack **a);

// push_swap_bench
char				*ft_strategy_writer(t_strategy strategy);
void				ft_benchmark(int disorder, t_strategy strategy);

// push_swap_complex_algorithm
void				ft_stack_arr_indexing(t_stack **a, int *arr, int size);
int					bit_long(int value);
int					max_bit_long(t_stack **a);
void				bubble_sort(int *arr, int size);
int					*stack_to_arr(t_stack **a);
void				ft_complex_algorithm_helper(t_stack **a, t_stack **b,
						int rotation, int size);
void				ft_complex_algorithm(t_stack **a);

// push_swap_control_form
void				ft_free_res(char **res);
void				format_lmt_ctrl(int argc, char **argv);

// push_swap_disorder_metric
float				ft_compute_disorder(t_stack **a);

// push_swap_init
t_stack				*stack_init(int argc, char **argv);

// push_swap_medium_algorithm
void				med_algo(t_stack **a);

// push_swap_push
void				ft_push_a(t_stack **a, t_stack **b, int *pa);
void				ft_push_b(t_stack **a, t_stack **b, int *pb);

// push_swap_reverse_rotate
void				ft_reverse_rotate_a(t_stack **a, int *rra);
void				ft_reverse_rotate_b(t_stack **b, int *rrb);
void				ft_reverse_rotate_a_b(t_stack **a, t_stack **b, int *rrr);

// push_swap_rotate
void				ft_rotate_a(t_stack **a, int *ra);
void				ft_rotate_b(t_stack **b, int *rb);
void				ft_rotate_a_b(t_stack **a, t_stack **b, int *rr);

// push_swap_simple
void				ft_three_sorter(t_stack **c);
void				ft_two_sorter(t_stack **b);
void				ft_helper_simple_algorithm(t_stack **a, int size);
void				ft_simple_algorithm(t_stack **a);

// push_swap_stack_clear
void				ft_stack_clear(t_stack *stack);

// push_swap_swap
void				ft_swap_a(t_stack **a, int *sa);
void				ft_swap_b(t_stack **b, int *sb);
void				ft_swap_a_b(t_stack **a, t_stack **b, int *ss);

// push_swap_utils
t_stack				*ft_new_stack(int new_value);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
int					ft_stack_size(t_stack **stack);

// push_swap
void				ft_free(char **doublearray);
int					flag_checker(char *arg);
t_stack				*ft_stack_creator(t_stack *a, char *argv[], int argc,
						char **split);
t_stack				*ft_reader(int argc, char *argv[]);

// unnecessary_functions
void				stack_printer(t_stack **a, char x);

#endif
