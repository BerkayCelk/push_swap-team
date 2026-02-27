#include "push_swap.h"

void	ft_swap_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->value)
		return ;
	first = *a;
	second = (*a)->next_value;
	first->next_value = second->next_value;
	second->next_value = first;
	*a = second;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->value)
		return ;
	first = *b;
	second = (*b)->next_value;
	first->next_value = second->next_value;
	second->next_value = first;
	*b = second;
	write(1, "sb\n", 3);
}

void	ft_swap_a_b(t_stack **a, t_stack **b)
{
	t_stack	*firsta;
	t_stack	*seconda;
	t_stack	*firstb;
	t_stack	*secondb;

	if (!*a || !(*a)->value)
		return ;
	firsta = *a;
	seconda = (*a)->next_value;
	firsta->next_value = seconda->next_value;
	seconda->next_value = firsta;
	*a = seconda;
	if (!*b || !(*b)->value)
		return ;
	firstb = *b;
	secondb = (*b)->next_value;
	firstb->next_value = secondb->next_value;
	secondb->next_value = firstb;
	*b = secondb;
	write(1, "ss\n", 3);
}
