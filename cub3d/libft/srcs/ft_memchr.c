/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:58:19 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 12:58:20 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp;
	size_t				i;

	if (n == 0)
		return (0);
	tmp = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		i++;
		tmp++;
	}
	return (0);
}
