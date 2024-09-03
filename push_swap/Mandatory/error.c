/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:48:09 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/18 10:04:10 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stacks *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top + 1)
	{
		j = 1;
		while (j < i)
		{
			if (a->arr[i] == a->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(t_stacks *a, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < a->top + 1)
		if (a->arr[i] < INT_MIN || a->arr[i] > INT_MAX)
			return (1);
	i = 0;
	while (i++ < a->top + 1)
	{
		j = 1;
		if (((av[i][0] == '-') || (av[i][0] == '+')) && ft_strlen(av[i]) == 1)
			return (1);
		if ((!(av[i][0] == '-') && !(av[i][0] == '+')) \
		&& !(av[i][0] >= '0' && av[i][0] <= '9'))
			return (1);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
	}
	return (0);
}

int	error_check(t_stacks *a, char **av)
{
	if (is_duplicate(a) || check_nbr(a, av))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (0);
}

void	sort_check(t_stacks *a)
{
	int	i;
	int	min;

	i = a->top;
	while (i > 0)
	{
		min = a->arr[i];
		if (min > a->arr[i - 1])
			return ;
		i--;
	}
	exit (0);
}
