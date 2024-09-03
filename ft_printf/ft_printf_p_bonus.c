/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:23:54 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/09 20:07:24 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_p(unsigned long long num, t_tags *p1)
{
	int	len;

	len = 0;
	if (!(p1->flags & LEFT) && p1->w > base_len_hex(num) + 2)
		len += put_pad(' ', (p1->w) - base_len_hex(num) - 2);
	write(1, "0x", 2);
	len += 2;
	ft_putnbr_hex(num, "0123456789abcdef");
	if ((p1->flags & LEFT) && p1->w > base_len_hex(num) + 2)
		len += put_pad(' ', (p1->w) - base_len_hex(num) - 2);
	len += base_len_hex(num);
	return (len);
}

int	base_len_hex(unsigned long long num)
{
	int	len;

	len = 1;
	while (num > 15)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex(unsigned long long num, char *base)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > base_len - 1)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}
