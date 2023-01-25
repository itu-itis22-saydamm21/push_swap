/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:54:51 by msaydam           #+#    #+#             */
/*   Updated: 2023/01/25 12:54:51 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate(t_data *a, t_data *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (i != j && a->array[i] == a->array[j])
				error_mes (a, b);
			j++;
		}
		i++;
	}
}

void	check_listed(t_data *a, t_data *b)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			counter = 0;
		i++;
	}
	if (counter == 1)
		free_function(a, b);
}

void	check_listed_for_checker(t_data *a, t_data *b, int *control)
{
	int	i;

	i = 0;
	(void)b;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}
