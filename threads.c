/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:26:55 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/01 16:04:59 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_threads(t_philo *philo, int num_philo)
{
    int i;

    i = 0;
    while(i < num_philo)
    {
        pthread_create(&(philo[i].id_thread), NULL, &routine, &(philo[i]));
        i = i + 2;
    }
    usleep(100);
    i = 1;
    while (i < num_philo)
    {
        pthread_create(&(philo[i].id_thread), NULL, &routine, &(philo[i]));
        i = i + 2;
    }
}

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo*)arg;
    while(1)
    {
        pthread_mutex_lock(&(philo->forks[philo->id_philo - 1]));
		ft_forks(philo);
		pthread_mutex_lock(&(philo->forks[philo->id_philo % philo->num_philo]));
		ft_forks(philo);
		ft_eat(philo);
		pthread_mutex_unlock(&(philo->forks[philo->id_philo % philo->num_philo]));
		pthread_mutex_unlock(&(philo->forks[philo->id_philo - 1]));
		ft_sleep(philo);
		ft_think(philo);
    }
}