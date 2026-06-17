/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:00:00 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 11:00:00 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = (*stack)->next_value;
	third = second->next_value;
	second->next_value = first;
	second->prev_value = NULL;
	first->next_value = third;
	first->prev_value = second;
	if (third)
		third->prev_value = first;
	*stack = second;
}

void	ft_swap_a(t_stack **a, t_benchmark *bench)
{
	if (!*a || !(*a)->next_value)
		return ;
	swap_stack(a);
	write(1, "sa\n", 3);
	bench->sa++;
}

void	ft_swap_b(t_stack **b, t_benchmark *bench)
{
	if (!*b || !(*b)->next_value)
		return ;
	swap_stack(b);
	write(1, "sb\n", 3);
	bench->sb++;
}

void	ft_swap_a_b(t_stack **a, t_stack **b, t_benchmark *bench)
{
	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	bench->ss++;
}
