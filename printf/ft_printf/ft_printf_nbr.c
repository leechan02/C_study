/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:29:22 by daniel            #+#    #+#             */
/*   Updated: 2022/09/09 18:28:04 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_diu(long long num, t_tags *p1)
{
	int	len;
	int	n_len;
	int	sign;
	int	pre;

	len = 0;
	n_len = base_len(num, 10) - (num < 0) - (p1->p == 0 && num == 0);
	sign = ((num >= 0 && (p1->flags & PLUS || p1->flags & SPACE)) || num < 0);
	pre = (p1->p - n_len) * (p1->p > n_len);
	if (!(p1->flags & LEFT) && !(p1->flags & ZERO) && p1->w > n_len)
		len += put_pad(' ', p1->w - n_len - sign - pre);
	len += is_sign(num, p1);
	if ((p1->flags & PRECISION) || (p1->flags & ZERO))
		len += pre_n_zero(num, p1);
	if (!(p1->p == 0 && num == 0))
	{
		ft_putnbr_base(num, "0123456789");
		len += n_len;
	}
	if ((p1->flags & LEFT) && p1->w > n_len)
		len += put_pad(' ', (p1->w) - len);
	return (len);
}

int	pre_n_zero(long long num, t_tags *p1)
{
	int	len;
	int	sign;
	int	n_len;

	len = 0;
	n_len = base_len(num, 10);
	sign = ((num >= 0 && (p1->flags & PLUS || p1->flags & SPACE)));
	if ((p1->p) > (p1->w) && (p1->flags & ZERO))
		len += put_pad('0', (p1->p) - n_len - sign);
	else if ((p1->p) <= (p1->w) && (p1->flags & ZERO))
		len += put_pad('0', (p1->w) - n_len - sign);
	else if ((p1->flags & PRECISION) && num < 0)
		len += put_pad('0', (p1->p) - n_len + 1);
	else if ((p1->flags & PRECISION))
		len += put_pad('0', (p1->p) - n_len);
	return (len);
}

void	ft_putnbr_base(long long num, char *base)
{
	long long	base_len;

	base_len = ft_strlen(base);
	if (num < 0)
		num *= -1;
	if (num > base_len - 1)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}

int	base_len(long long num, int base)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > base - 1)
	{
		num /= base;
		len++;
	}
	return (len);
}

int	is_sign(long long num, t_tags *p)
{
	if ((p->flags & PLUS) && num >= 0)
		return (ft_putchar('+'));
	else if ((p->flags & SPACE) && num >= 0)
		return (ft_putchar(' '));
	else if (num < 0)
		return (ft_putchar('-'));
	return (0);
}
