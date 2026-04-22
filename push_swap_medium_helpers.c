/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:00:00 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 11:00:00 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_top_chunk_pos(t_stack **a, int min_idx, int max_idx)
{
	t_stack	*current;
	int		pos;

	current = *a;
	pos = 0;
	while (current)
	{
		if (current->index >= min_idx && current->index <= max_idx)
			return (pos);
		current = current->next_value;
		pos++;
	}
	return (-1);
}

static int	find_bottom_chunk_pos(t_stack **a, int min_idx, int max_idx)
{
	t_stack	*current;
	int		pos;
	int		last_match;

	current = *a;
	pos = 0;
	last_match = -1;
	while (current)
	{
		if (current->index >= min_idx && current->index <= max_idx)
			last_match = pos;
		current = current->next_value;
		pos++;
	}
	return (last_match);
}

void	ft_rotate_to_chunk(t_stack **a, int min_idx, int max_idx,
		t_benchmark *bench)
{
	int	top_pos;
	int	bottom_pos;
	int	size;

	top_pos = find_top_chunk_pos(a, min_idx, max_idx);
	bottom_pos = find_bottom_chunk_pos(a, min_idx, max_idx);
	size = ft_stack_size(a);
	if (top_pos == -1 || bottom_pos == -1)
		return ;
	if (top_pos <= size - bottom_pos)
	{
		while (top_pos-- > 0)
			ft_rotate_a(a, bench);
	}
	else
	{
		while (bottom_pos++ < size)
			ft_reverse_rotate_a(a, bench);
	}
}

static int	find_target_pos(t_stack **b, int target_idx)
{
	t_stack	*current;
	int		pos;

	current = *b;
	pos = 0;
	while (current)
	{
		if (current->index == target_idx)
			return (pos);
		current = current->next_value;
		pos++;
	}
	return (-1);
}

void	ft_rotate_to_target_b(t_stack **b, int target_idx, t_benchmark *bench)
{
	int	pos;
	int	size;

	pos = find_target_pos(b, target_idx);
	size = ft_stack_size(b);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while ((*b)->index != target_idx)
			ft_rotate_b(b, bench);
	}
	else
	{
		while ((*b)->index != target_idx)
			ft_reverse_rotate_b(b, bench);
	}
}
