/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:54:04 by msaydam           #+#    #+#             */
/*   Updated: 2023/01/25 12:54:04 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_control(char c, t_data *a, t_data *b)
{
	if (c == '\0')
		error_mes(a, b);
}

char	**__arg_array(char **argv)
{
	char	*string;
	char	**new_string;
	int		index;
	char	*tmp;

	index = 0;
	string = ft_strdup("");
	while (argv[++index])
	{
		tmp = string;
		string = ft_strjoinn(tmp, argv[index]);
		free(tmp);
		tmp = string;
		string = ft_strjoinn(tmp, " ");
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
