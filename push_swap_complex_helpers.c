/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:00:00 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 11:00:00 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
