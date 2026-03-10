/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:22:44 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/02 16:13:44 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next_value)
		return ;
	last = ft_stacklast(*a);
	first = *a;
	second = (*a)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
    second->prev_value = NULL;
	*a = second;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->next_value)
		return ;
	last = ft_stacklast(*b);
	first = *b;
	second = (*b)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
    second->prev_value = NULL;
	*b = second;
	write(1, "ra\n", 3);
}
void	ft_rotate_a_b(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	last = ft_stacklast(*a);
	first = *a;
	second = (*a)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
    second->prev_value = NULL;
	*a = second;
    last = ft_stacklast(*b);
	first = *b;
	second = (*b)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
    second->prev_value = NULL;
	*b = second;
	write(1, "rr\n", 3);
}
