/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:49:41 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 09:49:43 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_triangle(t_stacks *p)
{
	int	depth;
	int	size;

	depth = 0;
	size = p->top + 1;
	while (size > power(3, depth) * 5)
		depth++;
	return (depth);
}

void	check_amt(int n, int depth, int *arr)
{
	int	i;
	int	j;
	int	temp;
	int	arr_size;

	arr[0] = n;
	arr_size = 1;
	i = 0;
	while (i < depth)
	{
		j = 0;
		while (j < arr_size)
		{
			temp = arr[j];
			arr[j] = temp / 3;
			arr[arr_size + j] = temp / 3 + temp % 3;
			arr[arr_size * 2 + j] = temp / 3;
			j++;
		}
		arr_size *= 3;
		i++;
	}
}

int	check_triangle(int idx)
{
	int	n;
	int	mirror;
	int	flip;
	int	dist;

	flip = 0;
	while (idx > 0)
	{
		n = 1;
		while (n <= idx)
			n *= 3;
		mirror = (n / 3) + (n < 3);
		dist = idx - mirror;
		dist %= mirror;
		idx = mirror - dist - 1;
		flip++;
	}
	return (flip);
}
