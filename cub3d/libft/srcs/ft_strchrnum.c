/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:55:11 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/31 18:57:10 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrnum(char *str, char ch)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ch)
			num++;
		i++;
	}
	return (num);
}
