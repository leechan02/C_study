/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:23:15 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/14 18:04:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_stacks
{
	int	*arr;
	int	top;
}	t_stacks;

/*checker*/
int		ft_strcmp(char *s1, char *s2);
int		main(int ac, char **av);

void	checker(t_stacks *a, t_stacks *b);
void	rules_error(t_stacks *a, t_stacks *b);
void	check_instruction(t_stacks *a, t_stacks *b, char *rules);

/*error*/
int		is_sort(t_stacks *a);
int		check_nbr(int ac, char **av);
int		error_check(int ac, char **av);
int		is_duplicate(int ac, char **av);

void	free_all(char *s);

/*stacks*/
int		pop(t_stacks *p);
int		empty(t_stacks *p);

void	init(t_stacks *p, int ac);
void	push(t_stacks *p, int num);
void	init_stacks(t_stacks *a, int ac, char **av);

/*rules*/
void	swap_ab(t_stacks *a, t_stacks *b, char c);
void	push_ab(t_stacks *a, t_stacks *b, char c);
void	rotate_ab(t_stacks *a, t_stacks *b, char c);
void	reverse_ab(t_stacks *a, t_stacks *b, char c);

/*check*/
int		main(int ac, char **av);
int		power(int num, int power);
void	sort(t_stacks *a, t_stacks *b);
void	sort_below_five(t_stacks *a, t_stacks *b, int num);

#endif