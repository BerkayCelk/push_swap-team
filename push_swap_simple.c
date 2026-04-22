/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 09:18:08 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/14 18:19:50 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current && current->next_value)
	{
		if (current->value > current->next_value->value)
			return (0);
		current = current->next_value;
	}
	return (1);
}

void	ft_three_sorter(t_stack **c,t_benchmark *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*c)->value;
	second = (*c)->next_value->value;
	third = (*c)->next_value->next_value->value;
	if (first < second && second < third)
		return ;
	if (first < third && third < second)
	{
		ft_swap_a(c,bench);
		ft_rotate_a(c,bench);
	}
	if (second < first && first < third)
		ft_swap_a(c,bench);
	if (second < third && third < first)
		ft_rotate_a(c,bench);
	if (third < first && first < second)
		ft_reverse_rotate_a(c,bench);
	if (third < second && second < first)
	{
		ft_swap_a(c,bench);
		ft_reverse_rotate_a(c,bench);
	}
}

void	ft_two_sorter(t_stack **b,t_benchmark *bench)
{
	int		size;
	t_stack	*first;
	t_stack	*second;

	size = ft_stack_size(b);
	if (size > 2)
		return ;
	first = *b;
	second = first->next_value;
	if (first->value > second->value)
		ft_swap_a(b,bench);
}

void	ft_helper_simple_algorithm(t_stack **a, int size,t_benchmark *bench)
{
	int	i;
	int	sorted;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		sorted = 0;
		j = 0;
		while (j < size - 1)
		{
			if ((*a)->value > (*a)->next_value->value)
			{
				ft_swap_a(a,bench);
				sorted = 1;
			}
			ft_rotate_a(a,bench);
			j++;
		}
		i++;
		ft_rotate_a(a,bench);
		if (sorted == 0)
			return ;
	}
}

void	ft_simple_algorithm(t_stack **a,t_benchmark *bench)
{
	int	size;

	size = ft_stack_size(a);
	if (size < 2 || is_sorted(a))
		return ;
	if (size == 2)
	{
		ft_two_sorter(a,bench);
		return ;
	}
	if (size == 3)
	{
		ft_three_sorter(a,bench);
		return ;
	}
	ft_helper_simple_algorithm(a, size,bench);
}


