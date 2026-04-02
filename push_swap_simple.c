/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 09:18:08 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/02 20:50:40 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_printer(t_stack **a, char x)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	printf("Stack %c\n", x);
	while (temp)
	{
		printf("Value: %d	Index: %d	Target_Index: %d	Cost_A:%d Cost_B: %d\n",
				temp->value,
				temp->index,
				temp->target_index,
				temp->cost_a,
				temp->cost_b);
		temp = temp->next_value;
	}
	printf("--------------------\n");
}

void	ft_three_sorter(t_stack **c)
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
		ft_swap_a(c);
		ft_rotate_a(c);
	}
	if (second < first && first < third)
		ft_swap_a(c);
	if (second < third && third < first)
		ft_rotate_a(c);
	if (third < first && first < second)
		ft_reverse_rotate_a(c);
	if (third < second && second < first)
	{
		ft_swap_a(c);
		ft_reverse_rotate_a(c);
	}
}

void	ft_two_sorter(t_stack **b)
{
	int		size;
	t_stack	*first;
	t_stack	*second;

	size = ft_stack_size(b);
	if (size > 2)
		return ;
	first = *b;
	second = first->next_value;
	if (second->value > first->value)
		ft_rotate_a(b);
}

void	ft_helper_simple_algorithm(t_stack **a, int size)
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
				ft_swap_a(a);
				sorted = 1;
			}
			ft_rotate_a(a);
			j++;
		}
		i++;
		ft_rotate_a(a);
		if (sorted == 0)
			return ;
	}
}

void	ft_simple_algorithm(t_stack **a)
{
	int	size;

	size = ft_stack_size(a);
	if (size == 3)
	{
		ft_three_sorter(a);
		return ;
	}
	ft_helper_simple_algorithm(a, size);
}
