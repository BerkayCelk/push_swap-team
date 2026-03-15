/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:35:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/15 16:27:41 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	
	a = ft_reader(argc, argv);
	stack_printer(&a,'A');
	printf("\n----------\n");
	ft_push_swap_complex_algorithm(&a);
	stack_printer(&a,'A');
}
