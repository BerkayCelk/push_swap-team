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

/* int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_new_stack(12);
	ft_stackadd_back(&a, ft_new_stack(13));
	ft_stackadd_back(&a, ft_new_stack(14));
	ft_stackadd_back(&a, ft_new_stack(15));
	ft_stackadd_back(&a, ft_new_stack(16));
	ft_stackadd_back(&a, ft_new_stack(17));

	stack_printer(&a);
	printf("-----\n");
	ft_push_b(&a,&b);
	ft_push_b(&a,&b);
	ft_push_b(&a,&b);
	stack_printer(&b);
} */
