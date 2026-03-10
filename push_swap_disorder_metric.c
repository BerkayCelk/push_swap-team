/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_disorder_metric.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 10:06:01 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/02 17:42:51 by ttezcan          ###   ########.fr       */
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
	return (mistakes / total_pairs);
}
int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	ft_stackadd_back(&a, ft_new_stack(9));
	ft_stackadd_back(&a, ft_new_stack(36));
	ft_stackadd_back(&a, ft_new_stack(78));
	ft_stackadd_back(&a, ft_new_stack(98));
	ft_stackadd_back(&a, ft_new_stack(36));
	ft_stackadd_back(&a, ft_new_stack(95));
	ft_stackadd_back(&a, ft_new_stack(93));
	ft_stackadd_back(&a, ft_new_stack(71));
	ft_stackadd_back(&a, ft_new_stack(82));
	ft_stackadd_back(&a, ft_new_stack(52));
	b = NULL;
	ft_stackadd_back(&b, ft_new_stack(9));
	ft_stackadd_back(&b, ft_new_stack(36));
	ft_stackadd_back(&b, ft_new_stack(36));
	ft_stackadd_back(&b, ft_new_stack(52));
	ft_stackadd_back(&b, ft_new_stack(71));
	ft_stackadd_back(&b, ft_new_stack(78));
	ft_stackadd_back(&b, ft_new_stack(82));
	ft_stackadd_back(&b, ft_new_stack(93));
	ft_stackadd_back(&b, ft_new_stack(95));
	ft_stackadd_back(&b, ft_new_stack(98));
	printf("%f\n", ft_compute_disorder(&a));
	printf("%f", ft_compute_disorder(&b));
	//stack_printer(&a);
}
