/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:37:50 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/14 09:06:56 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_ab(t_stacks *a, t_stacks *b, char c)
{
	int	tmp;

	if (c == 'a' || c == 'c')
	{
		tmp = a->arr[a->top];
		a->arr[a->top] = a->arr[a->top - 1];
		a->arr[a->top - 1] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		tmp = b->arr[b->top];
		b->arr[b->top] = b->arr[b->top - 1];
		b->arr[b->top - 1] = tmp;
	}
}

void	push_ab(t_stacks *a, t_stacks *b, char c)
{
	if (c == 'a')
		push(a, pop(b));
	else if (c == 'b')
		push(b, pop(a));
}

void	rotate_ab(t_stacks *a, t_stacks *b, char c)
{
	int	tmp;
	int	i;

	if (c == 'a' || c == 'c')
	{
		i = -1;
		tmp = a->arr[a->top];
		while (i++ < a->top + 1)
			a->arr[a->top - i] = a->arr[a->top - i - 1];
		a->arr[0] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		i = -1;
		tmp = b->arr[b->top];
		while (i++ < b->top + 1)
			b->arr[b->top - i] = b->arr[b->top - i - 1];
		b->arr[0] = tmp;
	}
}

void	reverse_ab(t_stacks *a, t_stacks *b, char c)
{
	int	tmp;
	int	i;

	if (c == 'a' || c == 'c')
	{
		i = -1;
		tmp = a->arr[0];
		while (++i < a->top)
			a->arr[i] = a->arr[i + 1];
		a->arr[a->top] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		i = -1;
		tmp = b->arr[0];
		while (++i < b->top)
			b->arr[i] = b->arr[i + 1];
		b->arr[b->top] = tmp;
	}
}
