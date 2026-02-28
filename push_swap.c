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

static int	ft_word_counter(char const *s, char c)
{
	size_t	i;
	size_t	l;
	size_t	flag;

	flag = 1;
	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (flag == 1)
			{
				l++;
				flag = 0;
			}
		}
		else
			flag = 1;
		i++;
	}
	return (l);
}

static char	**ft_separator(int argc, char *argv[])
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		split[j] = *ft_split(argv[i], ' ');
		i++;
		j++;
	}
	return (split);
}

t_stack	*ft_stack_creator(t_stack *a, char *argv[], int argc, char **split)
{
	int	i;
	int	j;

	i = 1;
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

t_stack	*ft_reader(int argc, char *argv[],int start)
{
	int		i;
	char	**split;
	int		j;
	t_stack	*a;

	a = NULL;
	split = NULL;
	i = start;
	
	return (ft_stack_creator(a, argv, argc, split));
}


int	main(int argc, char *argv[])
{
	int		i;
	char	**split;
	t_stack	*temp;
	t_stack	*temp1;
	t_stack	*free1;

	temp = ft_reader(argc, argv);
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next_value;
	}
	//system("Leaks a.out");
}
