/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:37:50 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/13 13:21:29 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else if (c == 'c')
		ft_printf("ss\n");
}

void	push_ab(t_stacks *a, t_stacks *b, char c)
{
	if (c == 'a')
	{
		push(a, pop(b));
		ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		push(b, pop(a));
		ft_printf("pb\n");
	}
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
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else if (c == 'c')
		ft_printf("rr\n");
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
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	else if (c == 'c')
		ft_printf("rrr\n");
}
