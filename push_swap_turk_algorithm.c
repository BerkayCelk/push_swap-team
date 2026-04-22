/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:55:56 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/21 05:22:43 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_indexing(t_stack **a)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next_value;
	}
}

void	ft_push_swap_cost_a(t_stack **a)
{
	int		size;
	t_stack	*temp;

	temp = *a;
	size = ft_stack_size(a);
	while (temp)
	{
		if (temp->index <= size / 2)
			temp->cost_a = temp->index;
		else
			temp->cost_a = -(size - temp->index);
		temp = temp->next_value;
	}
}

void	ft_push_swap_cost_b(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_a = *a;
	temp_b = *b;
	size = ft_stack_size(b);
	while (temp_b)
	{
		while (temp_a)
		{
			temp_b->target_index = ft_push_swap_finding_target_node(b,
																	temp_a->value);
			temp_a = temp_a->next_value;
		}
		if (temp_b->target_index <= size / 2)
			temp_b->cost_b = temp_b->target_index;
		else
			temp_b->cost_b = -(size - temp_b->target_index);
		temp_b = temp_b->next_value;
	}
}

t_stack	*find_max_stack(t_stack **a)
{
	int		max;
	t_stack	*temp;

	max = INT_MININMUM;
	temp = *a;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next_value;
	}
}

int	ft_push_swap_finding_target_node(t_stack **a, t_stack **b, int value_a)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target_node;
	t_stack	*first;
	int		best;
	t_stack	*max;

	max = find_max_stack(b);
	best = INT_MININMUM;
	temp_a = *a;
	while (temp_a)
	{
		temp_b = *b;
		while (temp_b)
		{
			if (temp_b->value < value_a && temp_b->value > best)
				best = temp_b;
			temp_b = temp_b->next_value;
		}
		temp_a = temp_a->next_value;
	}
	return (best);
}

void	ft_push_swap_turk_algorithm(t_stack **a)
{
	t_stack	*b;
	t_stack	target_node_of_a_in_b;
	int		size;
	t_stack	*temp1;
	t_stack	*temp2;

	b = NULL;
	ft_push_b(a, &b);
	ft_push_b(a, &b);
	size = ft_stack_size(a);
	ft_stack_indexing(a);
	ft_stack_indexing(&b);
	ft_push_swap_cost_a(a);
	ft_push_swap_cost_b(a, &b);
	//target_index_determinator(a, b);
	stack_printer(a, 'A');
	stack_printer(&b, 'B');
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_reader(argc, argv);
	ft_push_b(&a, &b);
	ft_push_b(&a, &b);
	//ft_push_swap_turk_algorithm(&a);
	stack_printer(&a, 'A');
	stack_printer(&b, 'B');
	printf("%d", ft_push_swap_finding_target_node(&b, a->value));
}
