/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:09:46 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 16:36:03 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_triangle_a(t_stacks *a, t_stacks *b, t_triangle *tri, int idx)
{
	int			num;
	int			max;
	t_limits	l;

	l.flags = 0;
	l.a = tri->amt[idx];
	l.b = tri->amt[(tri->tri_num * 2) - idx - 1];
	l.c = tri->amt[(tri->tri_num * 3) - idx - 1];
	num = l.a + l.b + l.c;
	while (num--)
	{
		max = find_max(a->arr[0], b->arr[b->top], b->arr[0], l);
		merge_to_a_norm(a, b, &l, max);
		if (empty(b))
		{
			l.flags |= B_LIMIT;
			l.flags |= C_LIMIT;
		}
	}
}

void	merge_reverse_a(t_stacks *a, t_stacks *b, t_triangle *tri, int idx)
{
	int			num;
	int			min;
	t_limits	l;

	l.flags = 0;
	l.a = tri->amt[idx];
	l.b = tri->amt[(tri->tri_num * 2) - idx - 1];
	l.c = tri->amt[(tri->tri_num * 3) - idx - 1];
	num = l.a + l.b + l.c;
	while (num--)
	{
		min = find_min(a->arr[0], b->arr[b->top], b->arr[0], l);
		merge_to_a_norm(a, b, &l, min);
		if (empty(b))
		{
			l.flags |= B_LIMIT;
			l.flags |= C_LIMIT;
		}
	}
}

void	merge_triangle_b(t_stacks *a, t_stacks *b, t_triangle *tri, int idx)
{
	int			num;
	int			max;
	t_limits	l;

	l.flags = 0;
	l.a = tri->amt[idx];
	l.b = tri->amt[(tri->tri_num * 2) - idx - 1];
	l.c = tri->amt[(tri->tri_num * 3) - idx - 1];
	num = l.a + l.b + l.c;
	while (num--)
	{
		max = find_max(b->arr[0], a->arr[a->top], a->arr[0], l);
		merge_to_b_norm(a, b, &l, max);
		if (empty(a))
		{
			l.flags |= B_LIMIT;
			l.flags |= C_LIMIT;
		}
	}
}

void	merge_reverse_b(t_stacks *a, t_stacks *b, t_triangle *tri, int idx)
{
	int			num;
	int			min;
	t_limits	l;

	l.flags = 0;
	l.a = tri->amt[idx];
	l.b = tri->amt[(tri->tri_num * 2) - idx - 1];
	l.c = tri->amt[(tri->tri_num * 3) - idx - 1];
	num = l.a + l.b + l.c;
	while (num--)
	{
		min = find_min(b->arr[0], a->arr[a->top], a->arr[0], l);
		merge_to_b_norm(a, b, &l, min);
		if (empty(a))
		{
			l.flags |= B_LIMIT;
			l.flags |= C_LIMIT;
		}
	}
}
