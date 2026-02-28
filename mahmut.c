/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mahmut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:38:16 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/28 10:47:40 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack *a;
	t_stack *b;
	t_stack *temp1;
	t_stack *temp2;

	a = ft_new_stack(42);
	b = ft_new_stack(55);
	ft_stackadd_back(&a,ft_new_stack(43));
	ft_stackadd_back(&a,ft_new_stack(44));
	ft_stackadd_back(&b,ft_new_stack(56));
	ft_stackadd_back(&b,ft_new_stack(57));
	ft_reverse_rotate_a(&a);
	ft_reverse_rotate_b(&b);
	ft_reverse_rotate_a_b(&a,&b);
	temp1 = a;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");
	temp2 = b;
	while (temp2)
	{
		printf("%d\n", temp2->value);
		temp2 = temp2->next_value;
	}
}