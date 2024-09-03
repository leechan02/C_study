/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophy_club.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:13 by euiclee           #+#    #+#             */
/*   Updated: 2023/05/01 17:32:00 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->n_philo)
		{
			pthread_mutex_lock(&table->m_last_ate);
			if (gettime() - table->philo[i].last_ate >= (uint64_t)table->t_die)
			{
				pthread_mutex_lock(&table->m_check);
				table->die = 1;
				if (table->philo[i].eat_count < table->must_eat)
					printf("%llu %d died\n",
						gettime() - table->start_time, table->philo[i].who);
				pthread_mutex_unlock(&table->m_check);
				pthread_mutex_unlock(&table->m_last_ate);
				return ;
			}
			pthread_mutex_unlock(&table->m_last_ate);
			usleep(100);
		}
	}
}

void	end_philo_club(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->m_check);
	pthread_mutex_destroy(&table->m_last_ate);
	free_all(table);
}

int	start_philo_club(t_table *table)
{
	int	i;

	i = -1;
	table->die = 0;
	table->start_time = gettime();
	while (++i < table->n_philo)
	{
		table->philo[i].last_ate = table->start_time;
		if (pthread_create(&table->philo[i].chair,
				NULL, routine, &table->philo[i]))
			return (1);
	}
	monitor(table);
	i = -1;
	if (table->n_philo == 1)
		pthread_detach(table->philo[++i].chair);
	else
		while (++i < table->n_philo)
			pthread_join(table->philo[i].chair, NULL);
	end_philo_club(table);
	return (0);
}
