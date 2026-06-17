/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttezcan <ttezcan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:26:09 by ttezcan           #+#    #+#             */
/*   Updated: 2026/04/23 03:30:04 by ttezcan          ###   ########.fr       */
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

static int	check_token(char *token, t_stack **seen)
{
	long	num;
	t_stack	*tmp;

	if (!ft_isnum(token))
		return (0);
	num = ft_atol(token);
	if (num < INT_MINIMUM || num > INT_MAXIMUM)
		return (0);
	tmp = *seen;
	while (tmp)
	{
		if (tmp->value == (int)num)
			return (0);
		tmp = tmp->next_value;
	}
	ft_stackadd_back(seen, ft_new_stack((int)num));
	return (1);
}

static int	check_argument(char *arg, t_stack **seen, int *has_number)
{
	char	**split;
	int		i;
	int		flag;

	flag = flag_checker(arg);
	if (flag >= SIMPLE && flag <= BENCH)
		return (1);
	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (ft_free_res(split), 0);
	i = 0;
	while (split[i])
	{
		if (!check_token(split[i], seen))
			return (ft_free_res(split), 0);
		*has_number = 1;
		i++;
	}
	ft_free_res(split);
	return (1);
}

int	ft_check_error(int argc, char *argv[])
{
	int		i;
	int		has_number;
	t_stack	*seen;

	seen = NULL;
	has_number = 0;
	i = 1;
	while (i < argc)
	{
		if (!check_argument(argv[i], &seen, &has_number))
		{
			ft_stack_clear(seen);
			ft_error();
			return (0);
		}
		i++;
	}
	if (!has_number)
	{
		ft_stack_clear(seen);
		ft_error();
		return (0);
	}
	ft_stack_clear(seen);
	return (1);
}
