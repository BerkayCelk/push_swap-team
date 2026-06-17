/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berkceli <berkceli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:00:00 by berkceli          #+#    #+#             */
/*   Updated: 2026/04/23 11:00:00 by berkceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **doublearray)
{
	size_t	i;

	if (!doublearray)
		return ;
	i = 0;
	while (doublearray[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		free(doublearray[i]);
	}
	free(doublearray);
}

int	flag_checker(char *arg)
{
	if (!arg)
		return (-1);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (0);
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		return (1);
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		return (2);
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (3);
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		return (4);
	return (-1);
}

static int	fill_stack_from_arg(t_stack **a, char *arg)
{
	int		j;
	long	value;
	char	**split;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		value = ft_atol(split[j]);
		if (*a == NULL)
			*a = ft_new_stack((int)value);
		else
			ft_stackadd_back(a, ft_new_stack((int)value));
		j++;
	}
	ft_free(split);
	return (1);
}

t_stack	*ft_stack_creator(t_stack *a, char *argv[], int argc)
{
	int		i;
	int		flag;

	i = 1;
	while (i < argc)
	{
		flag = flag_checker(argv[i]);
		if (flag >= SIMPLE && flag <= BENCH)
		{
			i++;
			continue ;
		}
		if (!fill_stack_from_arg(&a, argv[i]))
			return (a);
		i++;
	}
	return (a);
}

t_stack	*ft_reader(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
	return (ft_stack_creator(a, argv, argc));
}
