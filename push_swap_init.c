/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:35:32 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/02 20:21:33 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_dup(t_stack *stack, int num)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == num)
			return (1);
		temp = temp->next_value;
	}
	return (0);
}

static int	check_stack(char **res, t_stack **stack_a)
{
	int			j;
	long int	num;

	j = 0;
	while (res[j])
	{
		num = ft_atol(res[j]);
		if (ft_is_dup(*stack_a, num))
		{
			ft_free_res(res);
			ft_stack_clear(*stack_a);
			ft_error();
		}
		ft_stackadd_back(stack_a, ft_new_stack(num));
		j++;
	}
	ft_free_res(res);
	return (1);
}

t_stack	*stack_init(int argc, char **argv)
{
	t_stack		*stack_a;
	char		**res;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		check_stack(res, &stack_a);
		i++;
	}
	return (stack_a);
}
