/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:35:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/17 20:26:53 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_error(void)
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

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = ft_reader(argc, argv);
	if (ft_double_number(a) == 0)
		ft_error();
	stack_printer(&a, 'A');
	printf("\n----------\n");
	ft_push_swap_complex_algorithm(&a);
	stack_printer(&a, 'A');
}
