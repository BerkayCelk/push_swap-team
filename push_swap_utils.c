/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:20:15 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/02 20:50:54 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int new_value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prev_value = NULL;
	node->value = new_value;
	node->next_value = NULL;
	return (node);
}

void	ft_stackadd_front(t_stack **stack, t_stack *node)
{
	if (!node || !stack)
		return ;
	node->next_value = *stack;
	if (*stack)
		(*stack)->prev_value = node;
	*stack = node;
	(*stack)->prev_value = NULL;
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

void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!node || !stack)
		return ;
	else if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	temp = ft_stacklast(*stack);
	temp->next_value = node;
	node->prev_value = temp;
	node->next_value = NULL;
}

int ft_stack_size(t_stack **stack)
{
    int i = 0;
    t_stack *temp = *stack;
    while(temp)
    {
        i++;
        temp = temp->next_value;
    }
    return(i);
}

