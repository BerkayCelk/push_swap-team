/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:22:44 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/20 17:15:42 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_line_1(t_benchmark bench)
{
	ft_putstr_fd("[bench] total_ops: ", 1);
	ft_putnbr_fd(bench.total, 1);
	write(1, "\n", 1);
	ft_putstr_fd("[bench] sa: ", 1);
	ft_putnbr_fd(bench.sa, 1);
	ft_putstr_fd(" sb: ", 1);
	ft_putnbr_fd(bench.sb, 1);
	ft_putstr_fd(" ss: ", 1);
	ft_putnbr_fd(bench.ss, 1);
	ft_putstr_fd(" pa: ", 1);
	ft_putnbr_fd(bench.pa, 1);
	ft_putstr_fd(" pb: ", 1);
	ft_putnbr_fd(bench.pb, 1);
	write(1, "\n", 1);
}

void	ft_rotate_a(t_stack **a, t_benchmark *bench)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next_value)
		return ;
	last = ft_stacklast(*a);
	first = *a;
	second = (*a)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
	second->prev_value = NULL;
	*a = second;
	write(1, "ra\n", 3);
	bench->ra++;
}

void	ft_rotate_b(t_stack **b, t_benchmark *bench)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->next_value)
		return ;
	last = ft_stacklast(*b);
	first = *b;
	second = (*b)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
	second->prev_value = NULL;
	*b = second;
	write(1, "rb\n", 3);
	bench->rb++;
}
void	ft_rotate_a_b(t_stack **a, t_stack **b, t_benchmark *bench)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	last = ft_stacklast(*a);
	first = *a;
	second = (*a)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
	second->prev_value = NULL;
	*a = second;
	last = ft_stacklast(*b);
	first = *b;
	second = (*b)->next_value;
	last->next_value = first;
	first->prev_value = last;
	first->next_value = NULL;
	second->prev_value = NULL;
	*b = second;
	write(1, "rr\n", 3);
	bench->rr++;
}

void	bench_writer(t_benchmark bench)
{
	print_bench_line_1(bench);
	ft_putstr_fd("[bench] ra: ", 1);
	ft_putnbr_fd(bench.ra, 1);
	ft_putstr_fd(" rb: ", 1);
	ft_putnbr_fd(bench.rb, 1);
	ft_putstr_fd(" rr: ", 1);
	ft_putnbr_fd(bench.rr, 1);
	ft_putstr_fd(" rra: ", 1);
	ft_putnbr_fd(bench.rra, 1);
	ft_putstr_fd(" rrb: ", 1);
	ft_putnbr_fd(bench.rrb, 1);
	ft_putstr_fd(" rrr: ", 1);
	ft_putnbr_fd(bench.rrr, 1);
	write(1, "\n", 1);
}
