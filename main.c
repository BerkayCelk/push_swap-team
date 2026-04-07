/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:53 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/07 21:23:25 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total(t_benchmark bench)
{
	bench.total = bench.pa + bench.pb + bench.ra + bench.rb + bench.rr
		+ bench.rra + bench.rrb + bench.rrr + bench.sa + bench.sb + bench.ss;
	return (bench.total);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		disorder;
	int		i;
	int		s;

	format_lmt_ctrl(argc, argv);
	a = ft_reader(argc, argv);
	i = 0;
	while (i < 2)
	{
		s = flag_checker(argv[i]);
		if(s == )
		i++;
	}
}
