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

static int	is_optional_flag(char *arg)
{
	int	flag;

	flag = flag_checker(arg);
	return (flag >= SIMPLE && flag <= BENCH);
}

t_stack	*ft_stack_creator(t_stack *a, char *argv[], int argc)
{
	int		i;
	int		j;
	long	value;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (is_optional_flag(argv[i]))
		{
			i++;
			continue ;
		}
		split = ft_split(argv[i], ' ');
		if (!split)
			return (a);
		j = 0;
		while (split[j])
		{
			value = ft_atol(split[j]);
			if (a == NULL)
				a = ft_new_stack((int)value);
			else
				ft_stackadd_back(&a, ft_new_stack((int)value));
			j++;
		}
		ft_free(split);
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
