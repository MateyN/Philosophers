/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:22:00 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/09 15:01:19 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_args(t_philo *philo, int ac, char **av)
{
	philo->num_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->meal_opt = ft_atoi(av[5]);
}

void	ft_init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
}

void	ft_init_data(t_philo *philo, int ac, char **av, int num_philo)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*send;

	send = malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(send, NULL);
	forks = malloc(num_philo * sizeof(pthread_mutex_t));
	ft_init_forks(forks, num_philo);
	i = 0;
	while (i < num_philo)
	{
		ft_init_args(&(philo[i]), ac, av);
		philo[i].id_philo = i + 1;
		philo[i].count_meals = 0;
		philo[i].forks = forks;
		philo[i].send = send;
		philo[i].start = time_in_ms();
		philo[i].end = time_in_ms();
		i++;
	}
	ft_threads(philo, num_philo);
}
