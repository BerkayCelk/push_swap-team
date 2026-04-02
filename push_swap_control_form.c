/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_control_form.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 11:51:51 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/02 20:45:54 by ttezcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free_res(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	ft_check_res(char **res)
{
	int			j;
	long int	num;

	if (!res[0])
		return (0);
	j = 0;
	while (res[j])
	{
		if (!ft_isnum(res[j]))
			return (0);
		num = ft_atol(res[j]);
		if (num < -2147483648 || num > 2147483647)
			return (0);
		j++;
	}
	return (1);
}

void	format_lmt_ctrl(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (ft_check_res(res) == 0)
		{
			ft_free_res(res);
			ft_error();
		}
		i++;
		ft_free_res(res);
	}
}