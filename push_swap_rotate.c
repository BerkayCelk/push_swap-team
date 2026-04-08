/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:22:44 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/08 19:46:46 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (bench->bench == 0)
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
	if (bench->bench == 0)
		write(1, "ra\n", 3);
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
	if (bench->bench == 0)
		write(1, "rr\n", 3);
	bench->rr++;
}

void	bench_writer(t_benchmark bench)
{
	printf("[bench] total_ops: %d\n", bench.total);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench.sa, bench.sb,
			bench.ss, bench.pa, bench.pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench.ra,
			bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}
