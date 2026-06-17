/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:16:50 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/13 22:25:19 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bench_write_summary(float disorder, t_strategy strategy,
			t_benchmark *bench);
void	ft_bench_write_ops(t_benchmark *bench);

char	*ft_strategy_writer(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	else if (strategy == MEDIUM)
		return ("Medium");
	else if (strategy == COMPLEX)
		return ("Complex");
	else if (strategy == ADAPTIVE)
		return ("Adaptive");
	return (0);
}

void	ft_benchmark(float disorder, t_strategy strategy, t_benchmark *bench)
{
	ft_bench_write_summary(disorder, strategy, bench);
	ft_bench_write_ops(bench);
}
