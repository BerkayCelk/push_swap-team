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

int	main(void)
{
	t_stack *a = ft_new_stack(42);
	t_stack *b = ft_new_stack(55);
	t_stack *temp1;
	t_stack *temp2;
	a->next_value = ft_new_stack(43);
	b->next_value = ft_new_stack(56);
	temp1 = a;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");

	temp2 = b;
	while (temp2)
	{
		printf("%d\n", temp2->value);
		temp2 = temp2->next_value;
	}
	printf("----------------\n");
	ft_swap_a_b(&a, &b);
	temp1 = a;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");

	temp2 = b;
	while (temp2)
	{
		printf("%d\n", temp2->value);
		temp2 = temp2->next_value;
	}
	free(a);
	free(b);
}