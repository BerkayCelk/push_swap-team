#include "push_swap.h"

static void	stack_arr_indexing(t_stack **a, int *arr, int size)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == temp->value)
			{
				temp->index = i;
			}
			i++;
		}
		temp = temp->next_value;
	}
}

void	ft_five_sorter(t_stack **a, t_benchmark *bench)
{
	t_stack	*b;
	int		size;
	int		*arr;
	int		j;
	int		min_index;
	int		i;
	t_stack	*temp;

	b = NULL;
	size = ft_stack_size(a);
	arr = stack_to_arr(a);
	bubble_sort(arr, size);
	stack_arr_indexing(a, arr, size);
	j = 0;
	min_index = 0;
	i = 0;
	temp = a;
	while (temp)
	{
		if (temp->value < temp->next_value->value)
		{
			min_index = temp->index;
		}
		temp = temp->next_value;
	}
	while (j < size / 2)
	{
		if (min_index < size / 2)
        {
            
        }
        j++;
	}
}

int	main(void)
{
	t_stack		*a;
	t_benchmark	bench;
	int			size;
	int			*arr;

	a = ft_new_stack(50);
	ft_stackadd_back(&a, ft_new_stack(43));
	ft_stackadd_back(&a, ft_new_stack(32));
	ft_stackadd_back(&a, ft_new_stack(24));
	ft_stackadd_back(&a, ft_new_stack(11));
	size = ft_stack_size(&a);
	arr = stack_to_arr(&a);
	stack_arr_indexing(&a, arr, size);
	stack_printer(&a, 'A');
}
