/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_disorder_metric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 10:06:01 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/02 20:32:14 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_stack **a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*current;
	t_stack	*target;

	mistakes = 0;
	total_pairs = 0;
	current = *a;
	while (current)
	{
		target = current->next_value;
		while (target)
		{
			total_pairs++;
			if (current->value > target->value)
			{
				mistakes++;
			}
			target = target->next_value;
		}
		current = current->next_value;
	}
	if (total_pairs == 0)
		return (0.0f);
	return (mistakes / total_pairs);
}
