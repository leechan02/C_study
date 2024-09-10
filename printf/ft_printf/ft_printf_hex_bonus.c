/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:05:15 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/09 20:07:39 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_hex(unsigned int num, t_tags *p1)
{
	int	len;
	int	n_len;
	int	sign;
	int	pre;
	int	special;

	len = 0;
	n_len = base_len_hex(num) - (p1->p == 0 && num == 0);
	sign = (num >= 0 && p1->flags & SPACE);
	pre = (p1->p - n_len) * (p1->p > n_len);
	special = 2 * (((p1->flags & SPECIAL) > 0) && num > 0);
	if (!(p1->flags & LEFT) && !(p1->flags & ZERO) && p1->w > n_len)
		len += put_pad(' ', p1->w - n_len - sign - pre - special);
	len += is_sign(num, p1);
	if (!(p1->p == 0 && num == 0))
		len += print_ox(num, p1);
	if ((p1->flags & PRECISION) || (p1->flags & ZERO))
		len += pre_n_zero_hex(num, p1, len);
	if (!(p1->p == 0 && num == 0))
		print_hex(num, p1);
	len += n_len;
	if ((p1->flags & LEFT) && p1->w > n_len)
		len += put_pad(' ', (p1->w) - len);
	return (len);
}

int	print_ox(unsigned int num, t_tags *p1)
{
	int	len;

	len = 0;
	if ((p1->flags & SPECIAL) && (p1->flags & LOW) && num != 0)
	{
		write(1, "0x", 2);
		len += 2;
	}
	else if ((p1->flags & SPECIAL) && (p1->flags & UP) && num != 0)
	{
		write(1, "0X", 2);
		len += 2;
	}
	return (len);
}

void	print_hex(unsigned int num, t_tags *p1)
{
	if (p1->flags & LOW)
		ft_putnbr_hex(num, "0123456789abcdef");
	else if (p1->flags & UP)
		ft_putnbr_hex(num, "0123456789ABCDEF");
}

int	pre_n_zero_hex(unsigned int num, t_tags *p1, unsigned int total)
{
	int	len;
	int	n_len;

	len = 0;
	n_len = base_len_hex(num) + total;
	if ((p1->p) > (p1->w) && (p1->flags & ZERO))
		len += put_pad('0', (p1->p) - n_len);
	else if ((p1->p) <= (p1->w) && (p1->flags & ZERO))
		len += put_pad('0', (p1->w) - n_len);
	else if ((p1->flags & PRECISION))
		len += put_pad('0', (p1->p) - base_len_hex(num));
	return (len);
}
