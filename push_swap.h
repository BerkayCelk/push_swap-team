/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:20:43 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/02 20:53:22 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define INT_MININMUM -2147483648
#define INT_MAXIMUM 2147483647

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
}					t_benchmark;

t_stack				*ft_new_stack(int new_value);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
int					ft_stack_size(t_stack **stack);
void				ft_swap_a(t_stack **a);
void				ft_swap_b(t_stack **b);
void				ft_swap_a_b(t_stack **a, t_stack **b);
void				ft_push_a(t_stack **a, t_stack **b);
void				ft_push_b(t_stack **a, t_stack **b);
void				ft_rotate_a(t_stack **a);
void				ft_rotate_b(t_stack **b);
void				ft_rotate_a_b(t_stack **a, t_stack **b);
void				ft_reverse_rotate_a(t_stack **a);
void				ft_reverse_rotate_b(t_stack **b);
void				ft_reverse_rotate_a_b(t_stack **a, t_stack **b);
float				ft_compute_disorder(t_stack **a);
void				stack_printer(t_stack **a, char x);
void				ft_simple_algorithm(t_stack **a);
t_stack				*ft_stack_creator(t_stack *a, char *argv[], int argc,
						char **split);
t_stack				*ft_reader(int argc, char *argv[]);
void				ft_stack_indexing(t_stack **a);
void				ft_push_swap_turk_algorithm(t_stack **a);
int					ft_push_swap_finding_target_node(t_stack **b, int value_a);
void				ft_push_swap_cost_b(t_stack **a, t_stack **b);
void				ft_push_swap_cost_a(t_stack **a);
void				ft_stack_indexing(t_stack **a);
void				ft_complex_algorithm(t_stack **a);
int					max_bit_long(t_stack **a);
int					bit_long(int value);
int					*stack_to_arr(t_stack **a);
void				format_lmt_ctrl(int argc, char **argv);
t_stack				*stack_init(int argc, char **argv);
void				ft_stack_clear(t_stack *stack);
void				med_algo(t_stack **a);
long int			ft_atol(const char *str);
void				ft_error(void);
void				ft_free_res(char **res);
void				ft_adaptive_algorithm(t_stack **a);
