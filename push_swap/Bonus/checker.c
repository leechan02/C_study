/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:20:06 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/14 18:07:18 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rules_error(t_stacks *a, t_stacks *b)
{
	free (a->arr);
	free (b->arr);
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\n' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_instruction(t_stacks *a, t_stacks *b, char *rules)
{
	if (ft_strcmp(rules, "ra\n") == 0)
		rotate_ab(a, b, 'a');
	else if (ft_strcmp(rules, "rb\n") == 0)
		rotate_ab(a, b, 'b');
	else if (ft_strcmp(rules, "rr\n") == 0)
		rotate_ab(a, b, 'c');
	else if (ft_strcmp(rules, "sa\n") == 0)
		swap_ab(a, b, 'a');
	else if (ft_strcmp(rules, "sb\n") == 0)
		swap_ab(a, b, 'b');
	else if (ft_strcmp(rules, "ss\n") == 0)
		swap_ab(a, b, 'c');
	else if (ft_strcmp(rules, "rra\n") == 0)
		reverse_ab(a, b, 'a');
	else if (ft_strcmp(rules, "rrb\n") == 0)
		reverse_ab(a, b, 'b');
	else if (ft_strcmp(rules, "rrr\n") == 0)
		reverse_ab(a, b, 'c');
	else if (ft_strcmp(rules, "pa\n") == 0)
		push_ab(a, b, 'a');
	else if (ft_strcmp(rules, "pb\n") == 0)
		push_ab(a, b, 'b');
	else
		rules_error(a, b);
}

void	checker(t_stacks *a, t_stacks *b)
{
	char	*rules;

	while (1)
	{
		rules = get_next_line(0);
		if (rules == NULL)
			return ;
		check_instruction(a, b, rules);
	}
}

int	main(int ac, char **av)
{
	t_stacks	a;
	t_stacks	b;

	if (ac < 2)
		exit (0);
	if (!error_check(ac, av))
	{
		init_stacks(&a, ac, av);
		init(&b, ac);
		checker(&a, &b);
		if (is_sort(&a) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
