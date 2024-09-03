/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:48:09 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/14 18:06:49 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > INT_MAX)
			return (1);
	i = 0;
	while (++i < ac)
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

int	error_check(int ac, char **av)
{
	if (is_duplicate(ac, av) || check_nbr(ac, av))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (0);
}

int	is_sort(t_stacks *a)
{
	int	i;
	int	min;

	i = a->top;
	while (i > 0)
	{
		min = a->arr[i];
		if (min > a->arr[i - 1])
			return (1);
		i--;
	}
	return (0);
}
