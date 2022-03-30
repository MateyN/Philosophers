/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:41 by mnikolov          #+#    #+#             */
/*   Updated: 2022/03/30 11:34:44 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	long int			time;
	struct timeval		start;

	time = 0;
	if (gettimeofday(&start, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int delay)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < delay)
		usleep(delay / 10);
}