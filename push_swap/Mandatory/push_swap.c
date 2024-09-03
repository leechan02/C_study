/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:20:06 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/18 09:57:30 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power(int num, int pow)
{
	int	result;

	result = 1;
	while (pow--)
		result *= num;
	return (result);
}

void	sort(t_stacks *a, t_stacks *b)
{
	int			i;
	t_triangle	t;

	i = 0;
	t.size = a->top + 1;
	t.depth = num_triangle(a);
	t.tri_num = power(3, t.depth);
	t.amt = malloc(sizeof(int) * t.tri_num);
	if (!t.amt)
		exit (1);
	check_amt(a->top + 1, t.depth, t.amt);
	while (i < t.tri_num)
	{
		if (check_triangle(i) % 2 == 0)
			make_triangle(a, b, t.amt[i]);
		else
			make_reverse(a, b, t.amt[i]);
		i++;
	}
	merge(a, b, &t);
	free(t.amt);
}

void	sort_below_five(t_stacks *a, t_stacks *b, int num)
{
	if (num == 2)
		sort_two(a, b);
	else if (num == 3)
		sort_three(a, b);
	else if (num == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}

int	main(int ac, char **av)
{
	t_stacks	a;
	t_stacks	b;

	if (ac < 2)
		exit (0);
	init_stacks(&a, ac, av);
	if (!error_check(&a, av))
	{
		init(&b, ac);
		sort_check(&a);
		if (ac < 7)
			sort_below_five(&a, &b, ac - 1);
		else
			sort(&a, &b);
		free(b.arr);
	}
	free(a.arr);
	return (0);
}
