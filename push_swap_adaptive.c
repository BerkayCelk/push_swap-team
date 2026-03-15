/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_adaptive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:55:08 by ttezcan           #+#    #+#             */
/*   Updated: 2026/03/14 22:19:35 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_algorithm(t_stack **a)
{
	float	disorder;

	disorder = ft_compute_disorder(a);
    if(disorder < 0.2)
    {
        ft_simple_algorithm(a);
    }
    else if(0.2 <= disorder && disorder < 0.5)
    {
        ft_medium_algortihm(a);
    }
    else if (0.5 <= disorder)
    {
        ft_push_swap_complex_algorithm(a);
    }
}
