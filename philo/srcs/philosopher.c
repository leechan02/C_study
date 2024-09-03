/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:10:04 by euiclee           #+#    #+#             */
/*   Updated: 2023/05/16 09:56:59 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	if (philo->who % 2)
		usleep(table->n_philo * 42);
	while (1)
	{
		pthread_mutex_lock(&table->m_check);
		if (table->die == 1 || philo->eat_count >= table->must_eat)
		{
			pthread_mutex_unlock(&table->m_check);
			break ;
		}
		pthread_mutex_unlock(&table->m_check);
		philo_eat(philo, table);
		philo_sleep(philo, table);
		philo_print("is thinking", philo, table);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->forks[philo->left]);
	pthread_mutex_lock(&table->forks[philo->right]);
	philo_print("has taken a fork", philo, table);
	pthread_mutex_lock(&table->m_last_ate);
	philo_print("is eating", philo, table);
	philo->last_ate = gettime();
	philo->eat_count++;
	pthread_mutex_unlock(&table->m_last_ate);
	msleep(table->t_eat);
	pthread_mutex_unlock(&table->forks[philo->right]);
	pthread_mutex_unlock(&table->forks[philo->left]);
}

void	philo_sleep(t_philo *philo, t_table *table)
{
	philo_print("is sleeping", philo, table);
	msleep(table->t_sleep);
}

void	philo_print(char *str, t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->m_check);
	if (table->die != 1)
		printf("%llu %d %s\n", gettime() - table->start_time, philo->who, str);
	pthread_mutex_unlock(&table->m_check);
}
