/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:05:00 by ChatGPT           #+#    #+#             */
/*   Updated: 2026/04/22 14:05:00 by ChatGPT          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack_node(t_stack *node)
{
	ft_putstr_fd("Value: ", 1);
	ft_putnbr_fd(node->value, 1);
	ft_putstr_fd("\tIndex: ", 1);
	ft_putnbr_fd(node->index, 1);
	ft_putstr_fd("\tTarget_Index: ", 1);
	ft_putnbr_fd(node->target_index, 1);
	ft_putstr_fd("\tCost_A: ", 1);
	ft_putnbr_fd(node->cost_a, 1);
	ft_putstr_fd(" Cost_B: ", 1);
	ft_putnbr_fd(node->cost_b, 1);
	write(1, "\n", 1);
}

void	stack_printer(t_stack **a, char x)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	ft_putstr_fd("Stack ", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	while (temp)
	{
		print_stack_node(temp);
		temp = temp->next_value;
	}
	ft_putstr_fd("--------------------\n", 1);
}
