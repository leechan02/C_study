/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:31:05 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/09 20:08:05 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_alpha(const char **format, t_tags *p1)
{
	if (**format == 'x')
		p1->flags |= LOW;
	else if (**format == 'X')
		p1->flags |= UP;
}

void	check_tags(const char **format, t_tags *p1)
{
	while (ft_strchr("-+0 #", **format) != 0)
	{
		if (**format == '-')
			p1->flags |= LEFT;
		else if (**format == '+')
			p1->flags |= PLUS;
		else if (**format == '0')
			p1->flags |= ZERO;
		else if (**format == ' ')
			p1->flags |= SPACE;
		else if (**format == '#')
			p1->flags |= SPECIAL;
		(*format)++;
	}
	p1->w = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
	if (**format == '.')
	{
		p1->flags |= PRECISION;
		p1->flags &= ~ZERO;
		p1->p = ft_atoi(++(*format));
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
}

int	s_printf(va_list ap, const char **format)
{
	t_tags	p1;
	int		len;

	len = 0;
	p1.flags = 0;
	p1.w = 0;
	p1.p = -1;
	check_tags(format, &p1);
	check_alpha(format, &p1);
	if (**format == 's')
		len = ft_printf_s(va_arg(ap, char *), &p1);
	else if (**format == 'c')
		len = ft_printf_c(va_arg(ap, int), &p1);
	else if (**format == 'd' || **format == 'i')
		len = ft_printf_diu(va_arg(ap, int), &p1);
	else if (**format == 'u')
		len = ft_printf_diu(va_arg(ap, unsigned int), &p1);
	else if (**format == 'x' || **format == 'X')
		len = ft_printf_hex(va_arg(ap, unsigned int), &p1);
	else if (**format == 'p')
		len = ft_printf_p(va_arg(ap, unsigned long long), &p1);
	else if (**format == '%')
		len = ft_printf_c('%', &p1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned int	print_len;

	print_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			print_len++;
		}
		else
		{
			++format;
			print_len += s_printf(ap, &format);
			format++;
		}
	}
	va_end(ap);
	return (print_len);
}
