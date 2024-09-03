/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtarget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:00:03 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/24 10:03:41 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtarget(const char *str, const char *target)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	if (*str == '\n')
		return (FALSE);
	while (str[i] && str[i] != '\n')
	{
		j = 0;
		found = 0;
		while (target[j])
		{
			if (str[i] == target[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
