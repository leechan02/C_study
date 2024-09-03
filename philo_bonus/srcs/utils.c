/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:43:45 by euiclee           #+#    #+#             */
/*   Updated: 2023/01/26 16:09:24 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_table *table)
{
	free(table->forks);
	free(table->philo);
}

void	msleep(uint64_t sleep_ms)
{
	uint64_t	start_ms;

	start_ms = gettime();
	while (gettime() - start_ms < sleep_ms)
		usleep(100);
}

uint64_t	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	size_t	ret;
	size_t	idx;

	ret = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			ret = ret * 10 + (str[idx] - '0');
		else
			return (-1);
		idx++;
	}
	if (ret > INT_MAX)
		return (-1);
	return (ret);
}
