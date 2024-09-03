/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:53:02 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/24 20:01:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stronly(char *str, char *target)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (target[j])
		{
			if (str[i] == target[j])
				found = 1;
			j++;
		}
		if (found == 1)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
