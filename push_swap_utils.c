/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:20:15 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/26 20:55:54 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int new_value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev_value = NULL;
	new->value = new_value;
	new->next_value = NULL;
	return (new);
}
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	new->next_value = *stack;
	if (*stack)
		(*stack)->prev_value = new;
	*stack = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp->next_value != NULL)
	{
		temp = temp->next_value;
	}
	return (temp);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new || !stack)
		return ;
	else if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = ft_stacklast(*stack);
	temp->next_value = new;
	new->prev_value = temp;
}

/* int	main(void)
{
	int x = 32;
	t_stack *a = NULL;
	t_stack *b;
	while (0 < x--)
	{
		b = ft_new_stack(x);
		ft_stackadd_back(&a, b);
	}
	t_stack *temp = a;
	while (temp)
	{
		printf("%d\n", (temp->value));
		temp = temp->next_value;
	}
} */