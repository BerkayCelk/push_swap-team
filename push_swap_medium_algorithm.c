/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium_algorithm.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:15:17 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/08 20:23:22 by ttezcan          ###   ########.fr       */
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

static int	chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

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

static void	rotate_to_chunk(t_stack **a, int min_idx, int max_idx,
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

static void	push_chnk_b(t_stack **a, t_stack **b, int size, t_benchmark *bench)
{
	int	chunk_len;
	int	chunk_start;
	int	chunk_end;
	int	pushed;

	chunk_len = chunk_size(size);
	chunk_start = 0;
	while (chunk_start < size)
	{
		chunk_end = chunk_start + chunk_len - 1;
		if (chunk_end >= size)
			chunk_end = size - 1;
		pushed = chunk_start;
		while (pushed <= chunk_end)
		{
			rotate_to_chunk(a, chunk_start, chunk_end, bench);
			ft_push_b(a, b, bench);
			if (*b && (*b)->next_value
				&& (*b)->index < chunk_start + ((chunk_end - chunk_start + 1) / 2))
				ft_rotate_b(b, bench);
			pushed++;
		}
		chunk_start += chunk_len;
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

static void	rotate_to_target_b(t_stack **b, int target_idx, t_benchmark *bench)
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

static void	push_back_a(t_stack **a, t_stack **b, int size, t_benchmark *bench)
{
	int	chunk_len;
	int	chunk_end;
	int	chunk_start;
	int	target_idx;

	chunk_len = chunk_size(size);
	chunk_end = size - 1;
	while (chunk_end >= 0)
	{
		chunk_start = chunk_end - chunk_len + 1;
		if (chunk_start < 0)
			chunk_start = 0;
		target_idx = chunk_end;
		while (target_idx >= chunk_start)
		{
			rotate_to_target_b(b, target_idx, bench);
			ft_push_a(a, b, bench);
			target_idx--;
		}
		chunk_end = chunk_start - 1;
	}
}

void	med_algo(t_stack **a, t_benchmark *bench)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = ft_stack_size(a);
	if (size <= 3)
	{
		ft_simple_algorithm(a, bench);
		return ;
	}
	set_rnk_index(a);
	push_chnk_b(a, &b, size, bench);
	push_back_a(a, &b, size, bench);
}

