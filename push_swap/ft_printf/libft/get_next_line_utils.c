/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:53:29 by euiclee           #+#    #+#             */
/*   Updated: 2022/10/13 13:04:16 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = get_strlen(dst);
	src_len = get_strlen(src);
	i = 0;
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (*dst != '\0')
		dst++;
	while (src && dst_len + i + 1 < dstsize && *src != '\0' )
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

size_t	get_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*get_calloc(size_t count, size_t size)
{
	void	*dst;
	char	*tmp;
	int		len;

	dst = (void *)malloc(size * count);
	if (dst == NULL)
		return (0);
	tmp = dst;
	len = size * count;
	while (len--)
		*tmp++ = 0;
	return (dst);
}

char	*get_strchr(const char *s, int c)
{
	unsigned char	*s_tmp;

	if (!s)
		return (0);
	s_tmp = (unsigned char *)s;
	while (*s_tmp != (unsigned char)c)
	{
		if (*s_tmp == '\0')
			return (0);
		s_tmp++;
	}
	return ((char *)s_tmp);
}
