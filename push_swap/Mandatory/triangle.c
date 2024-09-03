/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:20:30 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 13:34:09 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_triangle(t_stacks *a, t_stacks *b, int amt)
{
	if (amt == 1)
		push_ab(a, b, 'b');
	else if (amt == 2)
		make_two(a, b);
	else if (amt == 3)
		make_three(a, b);
	else if (amt == 4)
		make_four(a, b);
	else if (amt == 5)
		make_five(a, b);
	else if (amt == 6)
		make_six(a, b);
}

void	make_reverse(t_stacks *a, t_stacks *b, int amt)
{
	if (amt == 1)
		push_ab(a, b, 'b');
	else if (amt == 2)
		make_two_re(a, b);
	else if (amt == 3)
		make_three_re(a, b);
	else if (amt == 4)
		make_four_re(a, b);
	else if (amt == 5)
		make_five_re(a, b);
	else if (amt == 6)
		make_six_re(a, b);
}
