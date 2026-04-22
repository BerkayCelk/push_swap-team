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

static void	print_stack_node(t_stack *node)
{
	ft_putstr_fd("Value: ", 1);
	ft_putnbr_fd(node->value, 1);
	ft_putstr_fd("\tIndex: ", 1);
	ft_putnbr_fd(node->index, 1);
	ft_putstr_fd("\tTarget_Index: ", 1);
	ft_putnbr_fd(node->target_index, 1);
	ft_putstr_fd("\tCost_A: ", 1);
	ft_putnbr_fd(node->cost_a, 1);
	ft_putstr_fd(" Cost_B: ", 1);
	ft_putnbr_fd(node->cost_b, 1);
	write(1, "\n", 1);
}

void	stack_printer(t_stack **a, char x)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	ft_putstr_fd("Stack ", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	while (temp)
	{
		print_stack_node(temp);
		temp = temp->next_value;
	}
	ft_putstr_fd("--------------------\n", 1);
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
	if (second->value > first->value)
		ft_rotate_a(b,bench);
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
	if (size == 3)
	{
		ft_three_sorter(a,bench);
		return ;
	}
	ft_helper_simple_algorithm(a, size,bench);
}


