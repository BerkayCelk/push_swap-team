#include "push_swap.h"

void	ft_free(char **doublearray)
{
	size_t	i;

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
	else if (ft_strncmp(arg, "--adaptive", 11) == 0
			|| (-2147483648 <= ft_atol(arg) && ft_atol(arg) <= 2147483647))
		return (3);
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		return (4);
	return (-1);
}

t_stack	*ft_stack_creator(t_stack *a, char *argv[], int argc, char **split)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i][0] == '-')
		i++;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (a == NULL)
				a = ft_new_stack(ft_atol(split[j]));
			else
				ft_stackadd_back(&a, ft_new_stack(ft_atoi(split[j])));
			j++;
		}
		j = 0;
		ft_free(split);
		i++;
	}
	return (a);
}

t_stack	*ft_reader(int argc, char *argv[])
{
	char	**split;
	t_stack	*a;

	a = NULL;
	split = NULL;
	return (ft_stack_creator(a, argv, argc, split));
}
