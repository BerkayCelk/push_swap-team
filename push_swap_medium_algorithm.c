/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium_algorithm.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:15:17 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 05:15:27 by ttezcan          ###   ########.fr       */
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
			ft_rotate_to_chunk(a, chunk_start, chunk_end, bench);
			ft_push_b(a, b, bench);
			if (*b && (*b)->next_value && (*b)->index < chunk_start
				+ ((chunk_end - chunk_start + 1) / 2))
				ft_rotate_b(b, bench);
			pushed++;
		}
		chunk_start += chunk_len;
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
			ft_rotate_to_target_b(b, target_idx, bench);
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
	if (size <= 5)
	{
		ft_small_sort(a, bench);
		return ;
	}
	set_rnk_index(a);
	push_chnk_b(a, &b, size, bench);
	push_back_a(a, &b, size, bench);
}
