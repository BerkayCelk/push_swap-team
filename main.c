/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:55:53 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/20 17:15:47 by berkceli         ###   ########.fr       */
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

static t_strategy	get_strategy(int argc, char *argv[])
{
	int			i;
	int			selected_flag;
	t_strategy	strategy;

	strategy = ADAPTIVE;
	i = 1;
	while (i < argc)
	{
		selected_flag = flag_checker(argv[i]);
		if (selected_flag >= SIMPLE && selected_flag <= ADAPTIVE)
			strategy = selected_flag;
		i++;
	}
	return (strategy);
}

static void	run_strategy(t_stack **a, t_benchmark *bench, t_strategy strategy)
{
	if (strategy == SIMPLE)
		ft_simple_algorithm(a, bench);
	else if (strategy == MEDIUM)
		med_algo(a, bench);
	else if (strategy == COMPLEX)
		ft_complex_algorithm(a, bench);
	else
		ft_adaptive_algorithm(a, bench);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_benchmark	bench;
	float		disorder;
	int			b;
	t_strategy	strategy;

	b = is_there_bench(argv);
	init_bench(&bench);
	if (argc < 2)
		return (0);
	if (!ft_check_error(argc, argv))
		return (1);
	a = ft_reader(argc, argv);
	disorder = ft_compute_disorder(&a);
	strategy = get_strategy(argc, argv);
	bench.bench = b;
	run_strategy(&a, &bench, strategy);
	if (b == 1)
		ft_benchmark(disorder, strategy, &bench);
	ft_stack_clear(a);
	return (0);
}
