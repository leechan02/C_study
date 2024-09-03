/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_make_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:50:45 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 14:08:21 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_four_norm(t_stacks *a, t_stacks *b, int max)
{
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
	else if (max == a->arr[1])
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

void	make_five_norm(t_stacks *a, t_stacks *b, int max)
{
	if (max == a->arr[a->top - 2])
	{
		rotate_ab(a, b, 'a');
		swap_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
	}
	else if (max == a->arr[1])
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

void	make_six_norm(t_stacks *a, t_stacks *b, int max)
{
	if (max == a->arr[a->top - 2])
	{
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
		push_ab(a, b, 'b');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
	}
	else if (max == a->arr[2])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
		rotate_ab(a, b, 'a');
	}
	else if (max == a->arr[1])
	{
		reverse_ab(a, b, 'a');
		reverse_ab(a, b, 'a');
		push_ab(a, b, 'b');
		rotate_ab(a, b, 'a');
	}
}
