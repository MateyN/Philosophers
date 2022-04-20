/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:41 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/20 11:42:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    ft_init_args(t_philo *philo, int ac, char **av)
{
    philo->num_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->meal_opt = ft_atoi(av[5]);
}

void    ft_init_data(t_philo *philo, int ac, char **av, int num_philo)
{
    int     i;
    sem_t   *forks;
    sem_t   *send;
    
	sem_unlink("/semaphore");
	sem_unlink("/send");
	send = sem_open("/send", O_CREAT | O_EXCL, 644, 1);
	if (send == SEM_FAILED)
		exit(1);
	forks = sem_open("/semaphore", O_CREAT | O_EXCL, 644, num_philo);
	if (forks == SEM_FAILED)
		exit(1);
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
	create_process(philo, num_philo);
}