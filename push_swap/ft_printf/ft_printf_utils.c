/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:44:32 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/21 10:47:05 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	put_pad(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}
