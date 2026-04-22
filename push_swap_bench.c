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

int	ft_total(t_benchmark *bench)
{
	int	total;

	total = bench->pa + bench->pb + bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr + bench->sa
		+ bench->sb + bench->ss;
	return (total);
}

char	*ft_complexity_writer(float disorder, t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	else if (strategy == MEDIUM)
		return ("O(n\u221An)");
	else if (strategy == COMPLEX)
		return ("O(nlogn)");
	else if (strategy == ADAPTIVE)
	{
		if (0 <= disorder && disorder < 0.2)
			return ("O(n^2)");
		else if (0.2 <= disorder && disorder < 0.5)
			return ("O(n\u221An)");
		else if (0.5 <= disorder && disorder <= 1)
			return ("O(nlogn)");
	}
	return (0);
}

static void	ft_put_u2_fd(int value, int fd)
{
	char	c;

	c = (value / 10) + '0';
	write(fd, &c, 1);
	c = (value % 10) + '0';
	write(fd, &c, 1);
}

static void	ft_put_percent_fd(float disorder, int fd)
{
	int	scaled;

	scaled = (int)(disorder * 10000.0f + 0.5f);
	ft_putnbr_fd(scaled / 100, fd);
	write(fd, ".", 1);
	ft_put_u2_fd(scaled % 100, fd);
	write(fd, "%", 1);
}

void	ft_benchmark(float disorder, t_strategy strategy, t_benchmark *bench)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_put_percent_fd(disorder, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(ft_strategy_writer(strategy), 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(ft_complexity_writer(disorder, strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ft_total(bench), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}