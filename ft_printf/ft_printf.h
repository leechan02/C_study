/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:23:24 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/09 18:15:29 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define LEFT 1
# define PLUS 2
# define ZERO 4
# define SPACE 8
# define SPECIAL 16
# define PRECISION 32
# define LOW 64
# define UP 128
# define ERROR 256

typedef struct s_tags
{
	unsigned int	flags;
	int				w;
	int				p;
}	t_tags;

/*main*/
int		ft_printf(const char *format, ...);
int		s_printf(va_list ap, const char **format);

void	check_tags(const char **format, t_tags *p1);
void	check_alpha(const char **format, t_tags *p1);

/*utils*/
int		ft_putchar(char c);
int		put_pad(char c, int len);
int		ft_atoi(const char *str);

char	*ft_strchr(const char *s, int c);

void	ft_putnbr_base(long long num, char *base);

/*nbr*/
int		base_len(long long num, int base);
int		is_sign(long long num, t_tags *p);
int		pre_n_zero(long long num, t_tags *p1);
int		ft_printf_diu(long long num, t_tags *p1);

/*str*/
int		ft_strlen(const char *s);
int		ft_printf_c(char c, t_tags *p1);
int		ft_printf_s(char *str, t_tags *p1);

/*hex*/
int		print_ox(unsigned int num, t_tags *p1);
int		ft_printf_hex(unsigned int num, t_tags *p1);
int		pre_n_zero_hex(unsigned int num, t_tags *p1, unsigned int total);

void	print_hex(unsigned int num, t_tags *p1);

/*p*/
int		base_len_hex(unsigned long long num);
int		ft_printf_p(unsigned long long num, t_tags *p1);

void	ft_putnbr_hex(unsigned long long num, char *base);

#	endif