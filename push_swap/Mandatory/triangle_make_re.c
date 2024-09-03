/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_make_re.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:22:17 by daniel            #+#    #+#             */
/*   Updated: 2022/10/12 14:57:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_two_re(t_stacks *a, t_stacks *b)
{
	if (a->arr[a->top] > a->arr[a->top - 1])
		swap_ab(a, b, 'a');
	push_ab(a, b, 'b');
	push_ab(a, b, 'b');
}

void	make_three_re(t_stacks *a, t_stacks *b)
{
	int	min;

	min = f_three_mn(a->arr[a->top], a->arr[a->top - 1], a->arr[0]);
	if (min == a->arr[a->top])
	{
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[a->top - 1])
	{
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else
	{
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
	make_two_re(a, b);
}

void	make_four_re(t_stacks *a, t_stacks *b)
{
	int	min;

	min = f_four_mn(a->arr[a->top], a->arr[a->top - 1], a->arr[1], a->arr[0]);
	make_four_norm_re(a, b, min);
	make_three_re(a, b);
}

void	make_five_re(t_stacks *a, t_stacks *b)
{
	int			min;
	t_compare	c;

	init_five_num_norm(a, &c);
	min = f_five_mn(&c);
	if (min == a->arr[a->top])
		push_ab(a, b, 'b');
	else if (min == a->arr[a->top - 1])
	{
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
	else
		make_five_norm_re(a, b, min);
	make_four_re(a, b);
}

void	make_six_re(t_stacks *a, t_stacks *b)
{
	int			min;
	t_compare	c;

	init_six_num_norm(a, &c);
	min = f_six_mn(&c);
	if (min == a->arr[a->top])
	{
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[a->top - 1])
	{
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[0])
	{
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
	else
		make_six_norm_re(a, b, min);
	make_five_re(a, b);
}
