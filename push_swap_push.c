#include "push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next_value;
	if (*b)
		(*b)->prev_value = NULL;
	temp->next_value = NULL;
	temp->prev_value = NULL;
	ft_stackadd_front(a, temp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next_value;
	if (*a)
		(*a)->prev_value = NULL;
	temp->next_value = NULL;
	temp->prev_value = NULL;
	ft_stackadd_front(b, temp);
	write(1, "pb\n", 3);
}
