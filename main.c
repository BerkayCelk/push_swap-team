/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:35:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/02 17:44:13 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp1;
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
	b = ft_reader(argc, argv);
	temp1 = a;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");
    
	/* temp1 = b;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n"); */
	/* temp1 = b;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n"); */
}
