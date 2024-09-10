/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:44:32 by euiclee           #+#    #+#             */
/*   Updated: 2022/09/09 20:07:06 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_tmp;

	s_tmp = (unsigned char *)s;
	while (*s_tmp != (unsigned char)c)
	{
		if (*s_tmp == 0)
			return (0);
		s_tmp++;
	}
	return ((char *)s_tmp);
}

int	ft_atoi(const char *str)
{
	static int			i;
	long long			result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
