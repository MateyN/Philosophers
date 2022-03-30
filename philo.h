/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:44 by mnikolov          #+#    #+#             */
/*   Updated: 2022/03/30 11:36:10 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct  s_philo
{
    int             id_philo;
    pthread_t       id_thread;
    pthread_t       id_death;
    t_philo         *philo;
    t_arguments     args;
    pthread_mutex_t *right_fork;
    pthread_mutex_t left_fork;
    t_arguments     *pointer_arg;
    long int        eat_ms;
    unsigned int    eat_num;
    int             end;
}   t_philo;

typedef struct s_arguments
{
    int             num_philo;
    int             time_to_eat;
    int             time_to_sleep;
    int             eat_opt;
    long int        starting;
    int             philo_eat_end;
    int             stop;
    pthread_mutex_t write;
}   t_arguments;


void        ft_eating(t_philo *philo);
void        ft_sleeping(t_philo *philo);
void        ft_thinking(t_philo *philo);
void	    ft_write(char *str, t_philo *philo);
long int	get_time(void);
void	    ft_usleep(long int delay);

#endif