/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:58:26 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 12:58:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && (tmp_s1[i] == tmp_s2[i]))
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
