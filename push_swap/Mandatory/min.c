/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:14:28 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/12 16:34:47 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_three_mn(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}

int	f_four_mn(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < c && b < d)
		return (b);
	else if (c < d)
		return (c);
	else
		return (d);
}

int	f_five_mn(t_compare *n)
{
	if (n->a < n->b && n->a < n->c && n->a < n->d && n->a < n->e)
		return (n->a);
	else if (n->b < n->c && n->b < n->d && n->b < n->e)
		return (n->b);
	else if (n->c < n->d && n->c < n->e)
		return (n->c);
	else if (n->d < n->e)
		return (n->d);
	else
		return (n->e);
}

int	f_six_mn(t_compare *n)
{
	if (n->a < n->b && n->a < n->c && n->a < n->d && n->a < n->e && n->a < n->f)
		return (n->a);
	else if (n->b < n->c && n->b < n->d && n->b < n->e && n->b < n->f)
		return (n->b);
	else if (n->c < n->d && n->c < n->e && n->c < n->f)
		return (n->c);
	else if (n->d < n->e && n->d < n->f)
		return (n->d);
	else if (n->e < n->f)
		return (n->e);
	else
		return (n->f);
}

void	init_six_num_norm(t_stacks *a, t_compare *c)
{
	c->a = a->arr[a->top];
	c->b = a->arr[a->top - 1];
	c->c = a->arr[a->top - 2];
	c->d = a->arr[2];
	c->e = a->arr[1];
	c->f = a->arr[0];
}
