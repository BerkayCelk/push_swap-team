/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium_algorithm.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:15:17 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/02 19:22:31 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rnk_index(t_stack **a)
{
	t_stack	*crnt;
	t_stack	*compare;
	int		count;

	crnt = *a;
	while (crnt)
	{
		count = 0;
		compare = *a;
		while (compare)
		{
			if (compare->value < crnt->value)
				count++;
			compare = compare->next_value;
		}
		crnt->index = count;
		crnt = crnt->next_value;
	}
}

static int	max_pos(t_stack **b, int *id_x)
{
	t_stack	*temp;
	int		pos;
	int		max_pos;

	temp = *b;
	*id_x = temp->index;
	max_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index > *id_x)
		{
			*id_x = temp->index;
			max_pos = pos;
		}
		pos++;
		temp = temp->next_value;
	}
	return (max_pos);
}

static void	push_chnk_b(t_stack **a, t_stack **b, int range)
{
	int	cntr;

	cntr = 0;
	while (*a)
	{
		if ((*a)->index <= cntr)
		{
			ft_push_b(a, b);
			if (*b && (*b)->next_value)
				ft_rotate_b(b);
			cntr++;
		}
		else if ((*a)->index <= cntr + range)
		{
			ft_push_b(a, b);
			cntr++;
		}
		else
			ft_rotate_a(a);
	}
}

static void	push_back_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;
	int	id_x;

	while (*b)
	{
		pos = max_pos(b, &id_x);
		size = ft_stack_size(b);
		if (pos <= size / 2)
			while ((*b)->index != id_x)
				ft_rotate_b(b);
		else
			while ((*b)->index != id_x)
				ft_reverse_rotate_b(b);
		ft_push_a(a, b);
	}
}

void	med_algo(t_stack **a)
{
	t_stack	*b;
	int		size;
	int		range;

	b = NULL;
	size = ft_stack_size(a);
	if (size <= 3)
	{
		ft_simple_algorithm(a);
		return ;
	}
	set_rnk_index(a);
	if (size <= 100)
		range = 20;
	else
		range = 40;
	push_chnk_b(a, &b, range);
	push_back_a(a, &b);
}