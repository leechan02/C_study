/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:42:20 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 14:31:46 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	answer(unsigned long long int num, int buho)
{
	int	a;

	a = num * buho;
	if (buho == -1 && num > 9223372036854775807)
		return (-1);
	if (buho == 1 && num > 9223372036854775807)
		return (-1);
	return (a);
}

int	ft_atoi(const char *str)
{
	int						buho;
	int						i;
	unsigned long long int	num;

	num = 0;
	buho = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{	
		buho *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (answer(num, buho));
}
