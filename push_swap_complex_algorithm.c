/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_algorithm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:23 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/23 05:16:04 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_arr_indexing(t_stack **a, int *arr, int size)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == temp->value)
				temp->index = i;
			i++;
		}
		temp = temp->next_value;
	}
}

void	ft_complex_algorithm_helper(t_stack **a, t_stack **b, int rotation,
		t_benchmark *bench)
{
	int	i;
	int	j;
	int	size;

	size = ft_stack_size(a);
	i = 0;
	while (i < rotation)
	{
		j = 0;
		while (j < size)
		{
			if ((*a)->index >> i & 1)
				ft_rotate_a(a, bench);
			else
				ft_push_b(a, b, bench);
			j++;
		}
		while (ft_stack_size(b) > 0)
			ft_push_a(a, b, bench);
		i++;
	}
}

void	ft_complex_algorithm(t_stack **a, t_benchmark *bench)
{
	t_stack	*b;
	int		*arr;
	int		size;
	int		rotation;

	size = ft_stack_size(a);
	if (size == 3)
	{
		ft_three_sorter(a, bench);
		return ;
	}
	if (size == 5)
	{
		ft_small_sort(a, bench);
		return ;
	}
	b = NULL;
	arr = stack_to_arr(a);
	bubble_sort(arr, size);
	ft_stack_arr_indexing(a, arr, size);
	free(arr);
	rotation = max_bit_long(a);
	ft_complex_algorithm_helper(a, &b, rotation, bench);
}
