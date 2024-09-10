/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:54:16 by euiclee           #+#    #+#             */
/*   Updated: 2022/07/21 10:53:55 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
