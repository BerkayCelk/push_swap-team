/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mahmut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:35:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/02 20:48:39 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

int	ft_double_number(t_stack **a)
{
	int	*arr;
	int	i;
	int	size;
	int	j;

	arr = malloc(ft_stack_size(a) * sizeof(int));
	if (!arr)
		return (0);
	arr = stack_to_arr(a);
	i = 0;
	size = ft_stack_size(a);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	free(arr);
	return (1);
}
