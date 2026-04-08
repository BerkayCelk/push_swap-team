#include "push_swap.h"

void	ft_swap_a(t_stack **a,t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*a || !(*a)->value)
		return ;
	first = *a;
	second = (*a)->next_value;
	third = second->next_value;
	second->next_value = first;
	second->prev_value = NULL;
	first->next_value = third;
	first->prev_value = second;
	if (third)
		third->prev_value = first;
	*a = second;
	if(bench->bench == 0)
		write(1, "sa\n", 3);
	bench->sa++;
}

void	ft_swap_b(t_stack **b,t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*b || !(*b)->value)
		return ;
	first = *b;
	second = (*b)->next_value;
	third = second->next_value;
	second->next_value = first;
	second->prev_value = NULL;
	first->next_value = third;
	first->prev_value = second;
	if (third)
		third->next_value = first;
	*b = second;
	if(bench->bench == 0)
		write(1, "sb\n", 3);
	bench->pb++;
}

void	ft_swap_a_b(t_stack **a, t_stack **b,t_benchmark *bench)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*a || !(*a)->next_value || !*b || !(*b)->next_value)
		return ;
	first = *a;
	second = (*a)->next_value;
	third = second->next_value;
	second->next_value = first;
	second->prev_value = NULL;
	first->next_value = third;
	first->prev_value = second;
	third->next_value = first;
	*a = second;
	first = *b;
	second = (*b)->next_value;
	third = second->next_value;
	second->next_value = first;
	second->prev_value = NULL;
	first->next_value = third;
	first->prev_value = second;
	third->next_value = first;
	*b = second;
	if(bench->bench == 0)
		write(1, "ss\n", 3);
	bench->ss++;
}
