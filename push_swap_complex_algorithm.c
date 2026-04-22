/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_algorithm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:23 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/21 05:31:48 by ttezcan          ###   ########.fr       */
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

int	bit_long(int value)
{
	int	size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 2;
		size++;
	}
	return (size);
}

int	max_bit_long(t_stack **a)
{
	int	size;

	size = ft_stack_size(a);
	return (bit_long(size - 1));
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	dummy;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				dummy = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = dummy;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_arr(t_stack **a)
{
	int		size;
	int		i;
	int		*arr;
	t_stack	*temp;

	i = 0;
	size = ft_stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	temp = *a;
	while (temp)
	{
		arr[i] = temp->value;
		temp = temp->next_value;
		i++;
	}
	return (arr);
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
	b = NULL;
	arr = stack_to_arr(a);
	bubble_sort(arr, size);
	ft_stack_arr_indexing(a, arr, size);
	free(arr);
	rotation = max_bit_long(a);
	ft_complex_algorithm_helper(a, &b, rotation, bench);
}
