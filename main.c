/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:53 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/21 05:11:10 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_benchmark *bench)
{
	bench->bench = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
}

int	is_there_bench(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	int			s;
	int			i;
	int			b;
	t_benchmark	bench;
	float		disorder;
	int			ss;
	int			x;

	ss = 0;
	b = is_there_bench(argv);
	init_bench(&bench);
	if (argc < 2)
		return (0);
	/* else if (ft_check_error(argc, argv) == 0)
		return (0); */
	a = ft_reader(argc, argv);
	//stack_printer(&a, 'A');
	disorder = ft_compute_disorder(&a);
	i = 1;
	s = -1;
	while (i < argc)
	{
		x = flag_checker(argv[i]);
		if (x != -1)
		{
			s = x;
		}
		i++;
	}
	if (b == 1)
		bench.bench = 1;
	if (s == 0)
	{
		ss = 0;
		ft_simple_algorithm(&a, &bench);
	}
	else if (s == 1)
	{
		ss = 1;
		med_algo(&a, &bench);
	}
	else if (s == 2)
	{
		ss = 2;
		ft_complex_algorithm(&a, &bench);
	}
	else
	{
		ss = 3;
		ft_adaptive_algorithm(&a, &bench);
	}
	if (b == 1)
		ft_benchmark(disorder, ss, &bench);
	//stack_printer(&a, 'A');
	return (0);
}
