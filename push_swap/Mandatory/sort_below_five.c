/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:37:10 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/13 09:59:14 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *a, t_stacks *b)
{
	swap_ab(a, b, 'a');
}

void	sort_three(t_stacks *a, t_stacks *b)
{
	int	min;
	int	max;

	min = f_three_mn(a->arr[0], a->arr[1], a->arr[2]);
	max = f_three_mx(a->arr[0], a->arr[1], a->arr[2]);
	if (min == a->arr[0] && max == a->arr[1])
		reverse_ab(a, b, 'a');
	else if (min == a->arr[2] && max == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		swap_ab(a, b, 'a');
	}
	else if (min == a->arr[1] && max == a->arr[2])
		rotate_ab(a, b, 'a');
	else if (min == a->arr[1] && max == a->arr[0])
		swap_ab(a, b, 'a');
	else if (min == a->arr[0] && max == a->arr[2])
	{
		rotate_ab(a, b, 'a');
		swap_ab(a, b, 'a');
	}
}

void	sort_four(t_stacks *a, t_stacks *b)
{
	int	min;

	min = f_four_mn(a->arr[0], a->arr[1], a->arr[2], a->arr[3]);
	if (min == a->arr[0])
		reverse_ab(a, b, 'a');
	else if (min == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[2])
		swap_ab(a, b, 'a');
	push_ab(a, b, 'b');
	sort_three(a, b);
	push_ab(a, b, 'a');
}

void	sort_five(t_stacks *a, t_stacks *b)
{
	int			min;
	t_compare	c;

	init_five_norm(a, &c);
	min = f_five_mn(&c);
	if (min == a->arr[0])
		reverse_ab(a, b, 'a');
	else if (min == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[2])
	{
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
	}
	else if (min == a->arr[3])
		swap_ab(a, b, 'a');
	push_ab(a, b, 'b');
	sort_four(a, b);
	push_ab(a, b, 'a');
}

void	init_five_norm(t_stacks *a, t_compare *c)
{
	c->a = a->arr[0];
	c->b = a->arr[1];
	c->c = a->arr[2];
	c->d = a->arr[3];
	c->e = a->arr[4];
}
