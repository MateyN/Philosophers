/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:44 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/06 10:20:24 by mnikolov         ###   ########.fr       */
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
	int				meal_opt;
	int				count_meals;
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
void        ft_threads(t_philo *philo, int num_philo);
void		*meal_optional(void *arg);
void        *routine(void *arg);
long int	time_in_ms(void);
void		ft_usleep(long time);
int			ft_check_is_death(t_philo *philo, int nphilos);
int         check_is_number(char **av);
void		destroy_mutexes(int num_philo, \
    pthread_mutex_t *forks, pthread_mutex_t *send);

#endif