/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:35:05 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 16:35:08 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	re_cnt(int tri, int *amt)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < tri)
	{
		result += amt[i];
		i++;
	}
	return (result);
}

void	last_merge_norm(t_stacks *a, t_stacks *b, int size)
{
	while (size--)
	{
		reverse_ab(a, b, 'b');
		push_ab(a, b, 'a');
	}
}

void	merge(t_stacks *a, t_stacks *b, t_triangle *t)
{
	int			i;
	t_triangle	tri;

	tri.depth = t->depth;
	while (tri.depth)
	{
		i = 0;
		tri.tri_num = power(3, tri.depth - 1);
		tri.amt = malloc(sizeof(int) * tri.tri_num * 3);
		if (!tri.amt)
			exit (1);
		check_amt(t->size, tri.depth, tri.amt);
		if (empty(a))
			empty_a_norm(a, b, &tri, i);
		else if (empty(b))
			empty_b_norm(a, b, &tri, i);
		tri.depth--;
		free (tri.amt);
	}
	if (t->depth % 2 == 0)
		last_merge_norm(a, b, t->size);
}

void	empty_a_norm(t_stacks *a, t_stacks *b, t_triangle *tri, int i)
{
	int	re;

	re = re_cnt(tri->tri_num, tri->amt);
	while (re--)
		push_ab(a, b, 'a');
	while (i < tri->tri_num)
	{
		if (check_triangle(i) % 2 == 0)
			merge_triangle_a(a, b, tri, i);
		else
			merge_reverse_a(a, b, tri, i);
		i++;
	}
}

void	empty_b_norm(t_stacks *a, t_stacks *b, t_triangle *tri, int i)
{
	int	re;

	re = re_cnt(tri->tri_num, tri->amt);
	while (re--)
		push_ab(a, b, 'b');
	while (i < tri->tri_num)
	{
		if (check_triangle(i) % 2 == 0)
			merge_triangle_b(a, b, tri, i);
		else
			merge_reverse_b(a, b, tri, i);
		i++;
	}
}
