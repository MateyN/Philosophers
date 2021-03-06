/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:59 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/29 11:02:56 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void    ft_kill_processors(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->num_philo)
    {
        kill(philo[i].pid, SIGKILL);
        i++;
    }
}

void    *check_is_dead(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (time_in_ms() + 1 - philo->end > philo->time_to_die)
        {
            sem_wait(philo->send);
            printf("\033[0;31m%ld %d died\n\033[0m", \
		        (time_in_ms() - philo->start), philo->id_philo);
            exit(0);
        }
        usleep(100);
    }
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