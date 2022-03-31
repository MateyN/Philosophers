/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:44 by mnikolov          #+#    #+#             */
/*   Updated: 2022/03/31 19:21:10 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		id_thread;
	int				id_philo;
	int				num_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				die;
	int				eat_opt;
	int				meal_opt;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*send;
	long int		start;
	int long		end;
}	t_philo;

int			ft_atoi(const char *str);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_forks(t_philo *philo);
void		ft_is_dead(t_philo *philo);
long int	time_in_ms(void);
void		ft_usleep(long time);
int			ft_check_is_death(t_philo *philo, int nphilos);
void	destroy_mutexes(int num_philo, \
    pthread_mutex_t *forks, pthread_mutex_t *send);

#endif