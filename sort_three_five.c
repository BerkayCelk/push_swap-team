#include "push_swap.h"

static int	is_sorted_small(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current && current->next_value)
	{
		if (current->value > current->next_value->value)
			return (0);
		current = current->next_value;
	}
	return (1);
}

static int	find_min_pos(t_stack **a)
{
	t_stack	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	current = *a;
	min_value = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		current = current->next_value;
		pos++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stack **a, int min_pos, t_benchmark *bench)
{
	int	size;

	size = ft_stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ft_rotate_a(a, bench);
	}
	else
	{
		while (min_pos++ < size)
			ft_reverse_rotate_a(a, bench);
	}
}

static void	sort_four_five(t_stack **a, t_benchmark *bench)
{
	t_stack	*b;
	int		size;
	int		pushed;

	b = NULL;
	size = ft_stack_size(a);
	pushed = 0;
	while (size - pushed > 3)
	{
		rotate_min_to_top(a, find_min_pos(a), bench);
		ft_push_b(a, &b, bench);
		pushed++;
	}
	ft_three_sorter(a, bench);
	while (pushed-- > 0)
		ft_push_a(a, &b, bench);
}

void	ft_small_sort(t_stack **a, t_benchmark *bench)
{
	int	size;

	size = ft_stack_size(a);
	if (size < 2 || is_sorted_small(a))
		return ;
	if (size == 2)
	{
		ft_two_sorter(a, bench);
		return ;
	}
	if (size == 3)
	{
		ft_three_sorter(a, bench);
		return ;
	}
	sort_four_five(a, bench);
}
