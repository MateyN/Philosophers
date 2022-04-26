/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:51 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/26 10:55:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    ft_eat(t_philo *philo)
{
    sem_wait(philo->send);
    printf("\033[0;32m%ld %d is eating\n\033[0m", \
        (time_in_ms() - philo->start), philo->id_philo);
    sem_post(philo->send);
    philo->end = time_in_ms();
    ft_usleep(philo->time_to_eat);
    if (philo->args == 6)
	{
		philo->count_meals += 1;
		if (philo->count_meals== philo->meal_opt)
		{
			sem_post(philo->forks);
			sem_post(philo->forks);
			exit(2);
		}
	}
}

void	ft_sleep(t_philo *philo)
{
	sem_wait(philo->send);
	printf("\033[0;33m%ld %d is sleeping\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
	sem_post(philo->send);
	ft_usleep(philo->time_to_sleep);
}

void    ft_think(t_philo *philo)
{
    sem_wait(philo->send);
    printf("\033[0;35m%ld %d is thinking\n\033[0m", \
		(time_in_ms() - philo->start), philo->id_philo);
    sem_post(philo->send);
}

void    ft_forks(t_philo *philo)
{
    sem_wait(philo->send);
    printf("%ld %d has take a fork\n", \
		(time_in_ms() - philo->start), philo->id_philo);
}
