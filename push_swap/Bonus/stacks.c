/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:40:17 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/23 15:01 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pop(t_stacks *p)
{
	int	num;

	num = p->arr[p->top];
	p->top--;
	return (num);
}

int	empty(t_stacks *p)
{
	return (p->top == -1);
}

void	init(t_stacks *p, int ac)
{
	p->top = -1;
	p->arr = malloc(sizeof(int) * ac);
	if (!p->arr)
		exit (1);
}

void	push(t_stacks *p, int num)
{
	p->top++;
	p->arr[p->top] = num;
}

void	init_stacks(t_stacks *a, int ac, char **av)
{
	int	i;

	i = 0;
	init(a, ac);
	while (ac-- > 1)
		push(a, ft_atoi(av[ac]));
}
