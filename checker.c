/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:54:47 by msaydam           #+#    #+#             */
/*   Updated: 2023/01/25 12:54:47 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list_checker(int *control, t_data *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}

void	rotate_func(char *s, t_data *a, t_data *b)
{
	if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rev_rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rev_rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rotate_together(a, b, 1);
	else
		error_mes(a, b);
}

void	make_pros(t_data *a, t_data *b, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		swap(a, 1);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		swap(b, 1);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		swap_together(a, b, 1);
	else if (s[0] == 'r')
		rotate_func(&s[0], a, b);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		push(b, a, 1);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		push(a, b, 1);
	else
		error_mes(a, b);
}

void	read_lines(t_data *a, t_data *b)
{
	char	*tmp;
	char	*test;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			return ;
		test = tmp;
		while (*test)
		{
			if (*test == ' ')
				exit(1);
			test++;
		}
		make_pros(a, b, tmp);
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;
	int		control;

	control = -1;
	a.type = 'a';
	b.type = 'b';
	if (ac >= 2)
		reading(av, &a, &b);
	else
		return (0);
	duplicate(&a, &b);
	read_lines(&a, &b);
	check_list_checker(&control, &a);
	if (control == 1 && !b.size)
		write(2, "OK\n", 4);
	else if (!control || b.size != 0)
		write(2, "KO\n", 4);
	free(a.array);
	free(b.array);
	return (0);
}
