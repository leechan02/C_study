/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:53:27 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 12:53:31 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_assert(int expression, char *msg, int error_code)
{
	if (expression == FALSE)
	{
		perror(msg);
		exit(error_code);
	}
}
