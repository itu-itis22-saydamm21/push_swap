#include "push_swap.h"

char	**__arg_array(char **argv)
{
	char	*tmp;
	char	*string;
	char	**new_string;
	int		index;

	index = 0;
	string = ft_strdup("");
	while (argv[++index])
	{
		tmp = string;
		string = ft_strjoinn(string, argv[index]);
		free(tmp);
		tmp = string;
		string = ft_strjoinn(string, " ");
		free(tmp);
	}
	new_string = ft_split(string, ' ');
	free(string);
	return (new_string);
}

void	reading(char **argv, t_data *a, t_data *b)
{
	int		i;
	char	**new_string;

	i = 0;
	new_string = __arg_array(argv);
	while (new_string[i])
		i++;
	a->size = i;
	b->size = 0;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = -1;
	while (new_string[++i])
	{
		a->array[a->size - 1 - i] = ft_atoii(new_string[i], a, b);
		free(new_string[i]);
	}
	free(new_string);
}
