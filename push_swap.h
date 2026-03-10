/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:20:43 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/02 21:44:58 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev_value;
	int				value;
	struct s_stack	*next_value;
}					t_stack;

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
void				stack_printer(t_stack **a);
void				ft_simple_algorithm(t_stack **a);
t_stack				*ft_stack_creator(t_stack *a, char *argv[], int argc,
						char **split);
t_stack				*ft_reader(int argc, char *argv[]);
