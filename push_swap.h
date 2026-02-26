/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:20:43 by ttezcan           #+#    #+#             */
/*   Updated: 2026/02/26 21:26:18 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev_value;
	int				value;
	struct s_stack	*next_value;
}					t_stack;

t_stack	*ft_new_stack(int new_value);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
