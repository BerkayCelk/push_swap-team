/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_clear.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:35:04 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/02 20:22:06 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next_value;
		free(stack);
		stack = temp;
	}
}