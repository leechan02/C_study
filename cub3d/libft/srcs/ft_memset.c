/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:00:23 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/30 14:55:30 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	if (b == 0)
		return (0);
	tmp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(tmp + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
