/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:03:17 by mnikolov          #+#    #+#             */
/*   Updated: 2022/03/30 11:38:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(char *str, t_philo *philo)
{
	long int		time;

	time = -1;
	time = actual_time() - philo->pointer_arg->starting;
	if (time >= 0 && time <= 2147483647 && !check_death(philo, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id_philo, str);
	}
}

void    ft_eating(t_philo *philo)
{
    
}
void    ft_sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->pointer_arg->write);
	ft_write("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->pointer_arg->write);
	ft_usleep(philo->pointer_arg->time_to_sleep);
}
void    ft_thinking(t_philo *philo)
{

}
void    ft_dead(t_philo *philo)
{
    
}
