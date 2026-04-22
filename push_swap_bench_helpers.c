/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:00:00 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 11:00:00 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_write_count(char *label, int value, int fd)
{
	ft_putstr_fd(label, fd);
	ft_putnbr_fd(value, fd);
}

static void	ft_put_percent_fd(float disorder, int fd)
{
	int	scaled;

	scaled = (int)(disorder * 10000.0f + 0.5f);
	ft_putnbr_fd(scaled / 100, fd);
	write(fd, ".", 1);
	if (scaled % 100 < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(scaled % 100, fd);
	write(fd, "%", 1);
}

char	*ft_bench_complexity_writer(float disorder, t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	else if (strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	else if (strategy == COMPLEX)
		return ("O(nlogn)");
	else if (strategy == ADAPTIVE && disorder < 0.2)
		return ("O(n^2)");
	else if (strategy == ADAPTIVE && disorder < 0.5)
		return ("O(n*sqrt(n))");
	else if (strategy == ADAPTIVE)
		return ("O(nlogn)");
	return (0);
}

void	ft_bench_write_summary(float disorder, t_strategy strategy,
		t_benchmark *bench)
{
	int	total;

	total = bench->pa + bench->pb + bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr + bench->sa;
	total += bench->sb + bench->ss;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_put_percent_fd(disorder, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(ft_strategy_writer(strategy), 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(ft_bench_complexity_writer(disorder, strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_write_count("[bench] total_ops: ", total, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_bench_write_ops(t_benchmark *bench)
{
	ft_write_count("[bench] sa: ", bench->sa, 2);
	ft_write_count(" sb: ", bench->sb, 2);
	ft_write_count(" ss: ", bench->ss, 2);
	ft_write_count(" pa: ", bench->pa, 2);
	ft_write_count(" pb: ", bench->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_write_count("[bench] ra: ", bench->ra, 2);
	ft_write_count(" rb: ", bench->rb, 2);
	ft_write_count(" rr: ", bench->rr, 2);
	ft_write_count(" rra: ", bench->rra, 2);
	ft_write_count(" rrb: ", bench->rrb, 2);
	ft_write_count(" rrr: ", bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}
