/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:22:44 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/27 23:39:56 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a)
{
	int		len;
	int		i;
	t_stack	*last;
	t_stack	*temp;

	last = ft_stacklast(*a);
	len = ft_stack_size(a);
	i = 0;
	while (i < len / 2)
	{
		temp = *a;
		*a = last;
		last = temp;
        i++;
	}
}
