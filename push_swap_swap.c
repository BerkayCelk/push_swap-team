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
	write(1, "sa", 2);
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
	write(1, "sb", 2);
}

void	ft_swap_a_b(t_stack **a, t_stack **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	write(1, "ss", 2);
}

int	main(void)
{
	t_stack *a = ft_new_stack(42);
	t_stack *b = ft_new_stack(55);
	t_stack *temp;
	ft_stackadd_back(&a, b);

	temp = a;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next_value;
	}
	printf("---------------\n");
	ft_swap_a(&a);
	temp = a;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next_value;
	}
	free(a);
	free(b);
}