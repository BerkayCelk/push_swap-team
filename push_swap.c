#include "push_swap.h"

static void	ft_free(char **doublearray)
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
int	flag_checker(int argc, char *argv[])
{
	if (ft_strncmp(argv[1],"--simple",8))
		return (2);
	else
		return (1);
}

t_stack	*ft_stack_creator(t_stack *a, char *argv[], int argc, char **split)
{
	int	i;
	int	j;

	i = flag_checker(argc, argv);
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (a == NULL)
				a = ft_new_stack(ft_atoi(split[j]));
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

int	main(int argc, char *argv[])
{
	t_stack	*temp;

	temp = ft_reader(argc, argv);
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next_value;
	}
	system("Leaks a.out");
}
