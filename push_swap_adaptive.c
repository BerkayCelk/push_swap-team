/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_adaptive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:55:08 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/08 20:50:24 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	ft_adaptive_algorithm(t_stack **a,t_benchmark *bench)
{
	float	disorder;

	disorder = ft_compute_disorder(a);
    if(disorder < 0.2)
    {
        ft_simple_algorithm(a,bench);
        return(SIMPLE);
    }
    else if(0.2 <= disorder && disorder < 0.5)
    {
        med_algo(a,bench);
        return(MEDIUM);
    }
    else if (0.5 <= disorder)
    {
        ft_complex_algorithm(a,bench);
        return(COMPLEX);
    }
    return(ADAPTIVE);
}
