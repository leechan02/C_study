/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_make_re_norm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:48:45 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 16:35:18 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_four_norm_re(t_stacks *a, t_stacks *b, int min)
{
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
	else if (min == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
	}
	else
	{
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
	}
}

void	make_five_norm_re(t_stacks *a, t_stacks *b, int min)
{
	if (min == a->arr[a->top - 2])
	{
		rotate_ab(a, b, 'a');
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
	}
	else
	{
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
	}
}

void	make_six_norm_re(t_stacks *a, t_stacks *b, int min)
{
	if (min == a->arr[a->top - 2])
	{
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
	}
	else if (min == a->arr[2])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
	}
	else if (min == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
	}
}
