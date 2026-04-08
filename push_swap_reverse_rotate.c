/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:12:06 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/08 19:29:05 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_stack **a, t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (!*a || !(*a)->next_value)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	before_last = last->prev_value;
	before_last->next_value = NULL;
	last->next_value = first;
	first->prev_value = last;
	last->prev_value = NULL;
	*a = last;
	if (bench->bench == 0)
		write(1, "rra\n", 4);
	bench->rra++;
}

void	ft_reverse_rotate_b(t_stack **b, t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (!*b || !(*b)->next_value)
		return ;
	first = *b;
	last = ft_stacklast(*b);
	before_last = last->prev_value;
	before_last->next_value = NULL;
	last->next_value = first;
	first->prev_value = last;
	last->prev_value = NULL;
	*b = last;
	if (bench->bench == 0)
		write(1, "rrb\n", 4);
	bench->rrb++;
}
void	ft_reverse_rotate_a_b(t_stack **a, t_stack **b, t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	before_last = last->prev_value;
	before_last->next_value = NULL;
	last->next_value = first;
	first->prev_value = last;
	last->prev_value = NULL;
	*a = last;
	first = *b;
	last = ft_stacklast(*b);
	before_last = last->prev_value;
	before_last->next_value = NULL;
	last->next_value = first;
	first->prev_value = last;
	last->prev_value = NULL;
	*b = last;
	if (bench->bench == 0)
		write(1, "rrr\n", 4);
	bench->rrr++;
}
