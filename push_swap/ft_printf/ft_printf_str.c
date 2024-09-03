/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:38:59 by daniel            #+#    #+#             */
/*   Updated: 2022/09/21 10:54:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str, t_tags *p1)
{
	int	len;
	int	i;
	int	re;

	i = -1;
	len = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (p1->p <= 0 && (p1->flags & PRECISION))
		len = 0;
	else if (p1->p > 0 && p1->p < len)
		len = p1->p;
	re = len;
	if (!(p1->flags & LEFT) && p1->w > len)
		len += put_pad(' ', (p1->w) - len);
	while (re-- > 0 && str[++i] != '\0')
		ft_putchar(str[i]);
	if ((p1->flags & LEFT) && p1->w > len)
		len += put_pad(' ', (p1->w) - len);
	return (len);
}

int	ft_printf_c(char c, t_tags *p1)
{
	int	len;

	len = 1;
	if (!(p1->flags & LEFT) && (p1->flags & ZERO))
		len += put_pad('0', p1->w - 1);
	if (!(p1->flags & LEFT) && p1->w > 0)
		len += put_pad(' ', (p1->w) - len);
	ft_putchar(c);
	if ((p1->flags & LEFT) && p1->w > 0)
		len += put_pad(' ', (p1->w) - len);
	return (len);
}
