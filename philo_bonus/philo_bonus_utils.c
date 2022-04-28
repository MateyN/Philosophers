/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:59 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/27 10:43:58 by mnikolov         ###   ########.fr       */
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