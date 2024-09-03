/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:09:41 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/26 18:30:16 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(int ac, char **av, t_table *table)
{
	table->n_philo = ft_atoi(av[1]);
	table->t_die = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	table->must_eat = INT_MAX;
	if (ac == 6)
		table->must_eat = ft_atoi(av[5]);
	if (table->n_philo <= 0 || table->t_die <= 0 || table->t_eat <= 0
		|| table->t_sleep <= 0 || table->must_eat == -1)
		return (1);
	else
		return (0);
}

int	init_mutex(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
		return (1);
	i = -1;
	while (++i < table->n_philo)
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (free_all(table), 1);
	if (pthread_mutex_init(&table->m_check, NULL))
		return (free_all(table), 1);
	if (pthread_mutex_init(&table->m_last_ate, NULL))
		return (free_all(table), 1);
	return (0);
}

int	init_philo(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philo)
		return (free_all(table), 1);
	i = -1;
	while (++i < table->n_philo)
	{
		table->philo[i].who = i + 1;
		table->philo[i].eat_count = 0;
		table->philo[i].left = i;
		table->philo[i].right = (i + 1) % table->n_philo;
		table->philo[i].eat_count = 0;
		table->philo[i].table = table;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		return (write(2, ARG_ERROR, ft_strlen(ARG_ERROR)));
	if (init_arg(ac, av, &table))
		return (write(2, ARG_ERROR, ft_strlen(ARG_ERROR)));
	if (init_mutex(&table))
		return (write(2, ARG_ERROR, ft_strlen(ARG_ERROR)));
	if (init_philo(&table))
		return (write(2, ARG_ERROR, ft_strlen(ARG_ERROR)));
	if (start_philo_club(&table))
		return (write(2, ARG_ERROR, ft_strlen(ARG_ERROR)));
	return (0);
}
