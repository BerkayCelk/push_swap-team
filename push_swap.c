#include "push_swap.h"

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

char	**ft_separator(int argc, char *argv[])
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

void	ft_reader(int argc, char *argv[])
{
	int		i;
	char	**split;
	int		j;
	t_stack	*a;

	split = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (a == NULL)
			{
				a = ft_lstnew(ft_atoi(split[j]));
			}
			else
			{
				ft_lstadd_back(a, ft_atoi(split[j]));
			}
			j++;
		}
		while (a)
		{
			printf("%d", a->value);
			a = a->next_value;
		}
		while (split[j])
		{
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**split;

	ft_reader(argc, argv);
	//system("Leaks a.out");
}
