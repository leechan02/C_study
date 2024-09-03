/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:20:11 by daniel            #+#    #+#             */
/*   Updated: 2022/10/12 14:42:16 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_two(t_stacks *a, t_stacks *b)
{
	if (a->arr[a->top] < a->arr[a->top - 1])
		swap_ab(a, b, 'a');
	push_ab(a, b, 'b');
	push_ab(a, b, 'b');
}

void	make_three(t_stacks *a, t_stacks *b)
{
	int	max;

	max = f_three_mx(a->arr[a->top], a->arr[a->top - 1], a->arr[0]);
	if (max == a->arr[a->top])
	{
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (max == a->arr[a->top - 1])
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
	make_two(a, b);
}

void	make_four(t_stacks *a, t_stacks *b)
{
	int	max;

	max = f_four_mx(a->arr[a->top], a->arr[a->top - 1], a->arr[1], a->arr[0]);
	make_four_norm(a, b, max);
	make_three(a, b);
}

void	make_five(t_stacks *a, t_stacks *b)
{
	int			max;
	t_compare	c;

	init_five_num_norm(a, &c);
	max = f_five_mx(&c);
	if (max == a->arr[a->top])
		push_ab(a, b, 'b');
	else if (max == a->arr[a->top - 1])
	{
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
	else
		make_five_norm(a, b, max);
	make_four(a, b);
}

void	make_six(t_stacks *a, t_stacks *b)
{
	int			max;
	t_compare	c;

	init_six_num_norm(a, &c);
	max = f_six_mx(&c);
	if (max == a->arr[a->top])
	{
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (max == a->arr[a->top - 1])
	{
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (max == a->arr[0])
	{
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
	else
		make_six_norm(a, b, max);
	make_five(a, b);
}
