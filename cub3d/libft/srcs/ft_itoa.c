/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:45 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 12:56:54 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_measure_len(long n)
{	
	if (n < 10)
		return (1);
	return (1 + ft_measure_len(n / 10));
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	num;

	num = (long)n;
	if (num < 0)
		num *= -1;
	len = ft_measure_len(num);
	if (n < 0)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = '\0';
	while (len--)
	{
		ret[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
