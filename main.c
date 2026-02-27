/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:35:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/27 23:38:07 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp1;
	t_stack	*temp2;

	a = ft_new_stack(42);
	b = ft_new_stack(55);
	a->next_value = ft_new_stack(43);
	b->next_value = ft_new_stack(56);
	a->next_value->next_value = ft_new_stack(44);
	b->next_value->next_value = ft_new_stack(57);
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
	printf("----------------\n");
	ft_push_a(&a, &b);
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
	ft_push_b(&a, &b);
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
	free(a);
	free(b);
}
