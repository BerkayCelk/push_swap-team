/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:26:09 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/14 18:58:48 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}
static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_error(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (ft_isnum(argv[i]) != 0)
	{
		i++;
	}
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 1)
		{
			ft_error();
			return(0) ;
		}
		i++;
	}
	i = 1;
	while (ft_isnum(argv[i]) != 0 && i < argc)
	{
		i++;
	}
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
			{
				ft_error();
				return(0) ;
			}
			j++;
		}
		i++;
	}
	return(1) ;
}
