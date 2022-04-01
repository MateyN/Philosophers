/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:03:17 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/01 15:36:45 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("%ld %d is eating\n", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
	philo->end = time_in_ms();
	ft_usleep(philo->time_to_eat);
	(philo->meal_opt)++;
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("%ld %d is sleeping\n", \
		(time_in_ms() - philo->start), philo->id_philo);
	pthread_mutex_unlock(philo->send);
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->send);
	printf("%ld %d is thinking\n", \
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
	printf("%ld %d died\n", \
		(time_in_ms() - philo->start), philo->id_philo);
}