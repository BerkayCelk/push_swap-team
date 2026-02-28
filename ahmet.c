#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*temp1;

	a = ft_new_stack(42);
	a->next_value = ft_new_stack(43);
	a->next_value->next_value = ft_new_stack(44);
	temp1 = a;
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");
	ft_rotate_a(&a);
	while (temp1)
	{
		printf("%d\n", temp1->value);
		temp1 = temp1->next_value;
	}
	printf("---------------\n");
}
