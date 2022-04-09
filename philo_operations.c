/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:03:17 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/09 13:22:31 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("\033[0;32m%ld %d is eating\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
	philo->end = time_in_ms();
	ft_usleep(philo->time_to_eat);
	(philo->count_meals)++;
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("\033[0;33m%ld %d is sleeping\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("\033[0;35m%ld %d is thinking\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
}

void	ft_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("%ld %d has take a fork\n", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
}

void	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("\033[0;31m%ld %d died\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
}
