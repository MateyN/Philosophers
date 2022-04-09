/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:41 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/09 16:57:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_in_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(long time)
{
	long int	start;

	start = 0;
	start = time_in_ms();
	while ((time_in_ms() - start) < time)
		usleep(time / 10);
}

void	destroy_mutexes(int num_philo, \
    pthread_mutex_t *forks, pthread_mutex_t *send)
{
    int i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_destroy(&(forks[i]));
		i++;
	}
	pthread_mutex_destroy(send);
}

int ft_check_is_death(t_philo *philo, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		if (time_in_ms() + 10 - philo[i].end > philo[i].time_to_die)
		{
			ft_is_dead(&(philo[i]));
			destroy_mutexes(philo->num_philo, philo->forks, philo->send);
			return (0);
		}
	}
	return (0);
}

int	check_is_number(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}