/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:44 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/11 10:46:26 by mnikolov         ###   ########.fr       */
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
	pthread_t		id_thread;			//thread ID
	int				id_philo;			//philosopher's ID
	int				num_philo;			//number of philosophers
	int				time_to_eat;		//time to eat in milliseconds
	int				time_to_sleep;		//time to sleep in milliseconds
	int				time_to_die;		//time to die in milliseconds
	int				meal_opt;			//time of the last meal in milliseconds
	int				count_meals;		//number of meals (each time the philosopher eats count_meals++)
	pthread_mutex_t	*forks;				//forks mutex
	pthread_mutex_t	*send;				//message mutex
	long int		start;				//start time in milliseconds
	int long		end;				//1 when a philosopher ate meal_opt times, if not, 0
}	t_philo;

//---------- UTILS.C ----------//
int			ft_atoi(const char *str);

//---------- OPERATIONS.C ----------//
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_forks(t_philo *philo);
void		ft_is_dead(t_philo *philo);

//---------- THREADS.C ----------//
void        ft_threads(t_philo *philo, int num_philo);
void        *routine(void *arg);

//---------- THREADS.C ----------//
void    	ft_init_data(t_philo *philo, int ac, char **av, int num_philo);
void		ft_init_args(t_philo *philo, int ac, char **av);
void		ft_init_forks(pthread_mutex_t *forks, int num_philo);

//---------- PHILO.C ----------//
void		*meal_optional(void *arg);

//---------- PHILO UTILS.C ----------//
long int	time_in_ms(void);
void		ft_usleep(long time);
int			ft_check_is_death(t_philo *philo, int nphilos);
int         check_is_number(char **av);
void		destroy_mutexes(int num_philo, \
    pthread_mutex_t *forks, pthread_mutex_t *send);

#endif