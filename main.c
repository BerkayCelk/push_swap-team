/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:53 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/08 21:10:18 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*a;
	int			s;
	int			i;
	int			strategy_executed;
	t_benchmark	bench = {0};
	strategy_executed = 0;
	if (argc < 2)
		return (0);
	a = ft_reader(argc, argv);
	i = 1;
	while (i < argc)
	{
		s = flag_checker(argv[i]);
		if (s != -1)
		{
			if (s == 4)
			{
				ft_benchmark(ft_compute_disorder(&a), s, &bench);
				bench.bench = 1;
			}
			else if (s == 0)
				ft_simple_algorithm(&a, &bench);
			else if (s == 1)
				med_algo(&a, &bench);
			else if (s == 2)
				ft_complex_algorithm(&a, &bench);
			else if (s == 3)
				ft_adaptive_algorithm(&a, &bench);
			strategy_executed = 1;
		}
		i++;
	}
	if (!strategy_executed)
		ft_adaptive_algorithm(&a, &bench);
	return (0);
}
