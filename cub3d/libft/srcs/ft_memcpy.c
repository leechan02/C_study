/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:00:03 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 13:00:04 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(tmp + i) = *((const unsigned char *)src + i);
		i++;
	}
	return (dst);
}
