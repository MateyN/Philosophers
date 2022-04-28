/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:38 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/27 10:35:10 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_philo
{
    pid_t       pid;
    int         id_philo;
    int         num_philo;
    int         time_to_die;
    int         time_to_sleep;
    int         time_to_eat;
    int         meal_opt;
    int         count_meals;
    int         args;
    sem_t       *forks;
    sem_t       *send;
    long int    start;
    int long    end;
}   t_philo;

int         ft_atoi(const char *str);
void        ft_eat(t_philo *philo);
void        ft_sleep(t_philo *philo);
void        ft_think(t_philo *philo);
void        ft_forks(t_philo *philo);
void	    ft_usleep(long time);
void        ft_init_args(t_philo *philo, int ac, char **av);
void        ft_init_data(t_philo *philo, int ac, char **av, int num_philo);
void        *check_is_dead(void *arg);
void        ft_create_process(t_philo *philo, int num_philo);
void        ft_kill_processors(t_philo *philo);
int	        check_is_number(char **av);
void        routine(t_philo *philo);
long int    time_in_ms(void);

#endif