/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:23:15 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/18 09:59:37 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

# define A_LIMIT 1
# define B_LIMIT 2
# define C_LIMIT 4

typedef struct s_stacks
{
	int	*arr;
	int	top;
}	t_stacks;

typedef struct s_triangle
{
	int	tri_num;
	int	depth;
	int	size;
	int	*amt;
}	t_triangle;

typedef struct s_limits
{
	int	a;
	int	b;
	int	c;
	int	flags;
}	t_limits;

typedef struct s_compare
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;
}	t_compare;

/*error*/
int		is_duplicate(t_stacks *a);
int		check_nbr(t_stacks *a, char **av);
int		error_check(t_stacks *a, char **av);

void	sort_check(t_stacks *a);

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

/*push_swap*/
int		main(int ac, char **av);
int		power(int num, int power);
void	sort(t_stacks *a, t_stacks *b);
void	sort_below_five(t_stacks *a, t_stacks *b, int num);

/*sort_below_five*/
void	sort_two(t_stacks *a, t_stacks *b);
void	sort_three(t_stacks *a, t_stacks *b);
void	sort_four(t_stacks *a, t_stacks *b);
void	sort_five(t_stacks *a, t_stacks *b);
void	init_five_norm(t_stacks *a, t_compare *c);

/*check*/
int		check_triangle(int idx);
int		num_triangle(t_stacks *p);

void	check_amt(int n, int depth, int *arr);

/*sort*/
int		re_cnt(int tri, int *amt);

void	merge(t_stacks *a, t_stacks *b, t_triangle *t);
void	last_merge_norm(t_stacks *a, t_stacks *b, int size);
void	empty_b_norm(t_stacks *a, t_stacks *b, t_triangle *tri, int i);
void	empty_a_norm(t_stacks *a, t_stacks *b, t_triangle *tri, int i);

/*merge*/
void	merge_reverse_a(t_stacks *a, t_stacks *b, t_triangle *tri, int idx);
void	merge_reverse_b(t_stacks *a, t_stacks *b, t_triangle *tri, int idx);
void	merge_triangle_a(t_stacks *a, t_stacks *b, t_triangle *tri, int idx);
void	merge_triangle_b(t_stacks *a, t_stacks *b, t_triangle *tri, int idx);

/*merge_norm*/
int		find_max(int a, int b, int c, t_limits l);
int		find_min(int a, int b, int c, t_limits l);
void	merge_to_a_norm(t_stacks *a, t_stacks *b, t_limits *l, int com);
void	merge_to_b_norm(t_stacks *a, t_stacks *b, t_limits *l, int com);

/*max*/
int		f_six_mx(t_compare *n);
int		f_five_mx(t_compare *n);
int		f_three_mx(int a, int b, int c);
int		f_four_mx(int a, int b, int c, int d);

void	init_five_num_norm(t_stacks *a, t_compare *c);

/*min*/
int		f_six_mn(t_compare *n);
int		f_five_mn(t_compare *n);
int		f_three_mn(int a, int b, int c);
int		f_four_mn(int a, int b, int c, int d);

void	init_six_num_norm(t_stacks *a, t_compare *c);

/*triangle*/
void	make_triangle(t_stacks *a, t_stacks *b, int amt);
void	make_reverse(t_stacks *a, t_stacks *b, int amt);

/*triangle_make*/
void	make_two(t_stacks *a, t_stacks *b);
void	make_three(t_stacks *a, t_stacks *b);
void	make_four(t_stacks *a, t_stacks *b);
void	make_five(t_stacks *a, t_stacks *b);
void	make_six(t_stacks *a, t_stacks *b);

/*triangle_make_norm*/
void	make_four_norm(t_stacks *a, t_stacks *b, int max);
void	make_five_norm(t_stacks *a, t_stacks *b, int max);
void	make_six_norm(t_stacks *a, t_stacks *b, int max);

/*triangle_make_re*/
void	make_two_re(t_stacks *a, t_stacks *b);
void	make_three_re(t_stacks *a, t_stacks *b);
void	make_four_re(t_stacks *a, t_stacks *b);
void	make_five_re(t_stacks *a, t_stacks *b);
void	make_six_re(t_stacks *a, t_stacks *b);

/*triangle_make_re_norm*/
void	make_four_norm_re(t_stacks *a, t_stacks *b, int max);
void	make_five_norm_re(t_stacks *a, t_stacks *b, int max);
void	make_six_norm_re(t_stacks *a, t_stacks *b, int max);
#endif