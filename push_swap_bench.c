/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:16:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/07 17:14:20 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strategy_writer(t_strategy strategy)
{
	char	*a;

	a = NULL;
	if (strategy == SIMPLE)
		return ("Simple");
	else if (strategy == MEDIUM)
		return ("Medium");
	else if (strategy == COMPLEX)
		return ("Complex");
	else if (strategy == ADAPTIVE)
		return ("Adaptive");
}

void	ft_benchmark(int disorder, t_strategy strategy)
{
	t_benchmark bench = {0};
	printf("[bench] disorder: %d\n", disorder);
	printf("[bench] strategy: %s\n", ft_strategy_writer(strategy));
	printf("[bench] total_ops: %d\n", bench.total);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench.sa, bench.sb,
			bench.ss, bench.pa, bench.pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench.ra,
			bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}