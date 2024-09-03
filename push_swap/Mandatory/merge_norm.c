/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:23:28 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 16:34:07 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_a_norm(t_stacks *a, t_stacks *b, t_limits *l, int com)
{
	if (com == a->arr[0])
	{
		l->a--;
		if (l->a == 0)
			l->flags |= A_LIMIT;
		reverse_ab(a, b, 'a');
	}
	else if (!empty(b) && com == b->arr[b->top])
	{
		l->b--;
		if (l->b == 0)
			l->flags |= B_LIMIT;
		push_ab(a, b, 'a');
	}
	else if (!empty(b))
	{
		l->c--;
		if (l->c == 0)
			l->flags |= C_LIMIT;
		reverse_ab(a, b, 'b');
		push_ab(a, b, 'a');
	}
}

void	merge_to_b_norm(t_stacks *a, t_stacks *b, t_limits *l, int com)
{
	if (com == b->arr[0])
	{
		l->a--;
		if (l->a == 0)
			l->flags |= A_LIMIT;
		reverse_ab(a, b, 'b');
	}
	else if (!empty(a) && com == a->arr[a->top])
	{
		l->b--;
		if (l->b == 0)
			l->flags |= B_LIMIT;
		push_ab(a, b, 'b');
	}
	else if (!empty(a))
	{
		l->c--;
		if (l->c == 0)
			l->flags |= C_LIMIT;
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
}

int	find_max(int a, int b, int c, t_limits l)
{
	if (l.flags & A_LIMIT)
		a = INT_MIN;
	if (l.flags & B_LIMIT)
		b = INT_MIN;
	if (l.flags & C_LIMIT)
		c = INT_MIN;
	if (a > b && a > c)
		return (a);
	else if (b > c)
		return (b);
	else
		return (c);
}

int	find_min(int a, int b, int c, t_limits l)
{
	if (l.flags & A_LIMIT)
		a = INT_MAX;
	if (l.flags & B_LIMIT)
		b = INT_MAX;
	if (l.flags & C_LIMIT)
		c = INT_MAX;
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}
