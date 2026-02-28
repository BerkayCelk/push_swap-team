/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:22:44 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/28 10:09:45 by ttezcan          ###   ########.fr       */
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
	*a = second;
	(*a)->prev_value = NULL;
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
	*b = second;
	(*b)->prev_value = NULL;
	write(1, "ra\n", 3);
}
void	ft_rotate_a_b(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*first1;
	t_stack	*second1;
	t_stack	*first2;
	t_stack	*second2;

	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	last = ft_stacklast(*a);
	first1 = *a;
	second1 = (*a)->next_value;
	last->next_value = first1;
	first1->prev_value = last;
	first1->next_value = NULL;
	*a = second1;
	(*a)->prev_value = NULL;
	last = ft_stacklast(*b);
	first2 = *b;
	second2 = (*b)->next_value;
	last->next_value = first2;
	first2->prev_value = last;
	first2->next_value = NULL;
	*b = second2;
	(*b)->prev_value = NULL;
	write(1, "rr\n", 3);
}
