/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 09:18:08 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/10 10:39:57 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_printer(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next_value;
	}
}

void	ft_three_sorter(t_stack **c)
{
	int	first;
	int	second;
	int	third;

	first = (*c)->value;
	second = (*c)->next_value->value;
	third = (*c)->next_value->next_value->value;
	if (first < second && second < third)
		return ;
	if (first < third && third < second)
	{
		ft_swap_a(c);
		ft_rotate_a(c);
	}
	if (second < first && first < third)
		ft_swap_a(c);
	if (second < third && third < first)
		ft_rotate_a(c);
	if (third < first && first < second)
		ft_reverse_rotate_a(c);
	if (third < second && second < first)
	{
		ft_swap_a(c);
		ft_reverse_rotate_a(c);
	}
}

void	ft_simple_algorithm(t_stack **a)
{
	int	sorted;
	int	size;
	int	i;
	int	j;

	sorted = 0;
	i = 0;
	size = ft_stack_size(a);
	/* if (size == 3)
	{
		ft_three_sorter(a);
		return ;
	} */
	while (i < size - 1)
	{
		sorted = 0;
		j = 0;
		while (j < size - 1)
		{
			if ((*a)->value > (*a)->next_value->value)
			{
				ft_swap_a(a);
				sorted = 1;
			}
			ft_rotate_a(a);
			j++;
		}
		i++;
		ft_rotate_a(a);
		if (sorted == 0)
		{
			printf("-----\n");
			stack_printer(a);
			return ;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	//t_stack	*b;
	a = ft_reader(argc, argv);
	stack_printer(&a);
	printf("----------\n");
	ft_simple_algorithm(&a);
	stack_printer(&a);
	//printf("----------\n");
	/* stack_printer(&a);
	printf("----------\n"); */
	//stack_printer(&b);
}
