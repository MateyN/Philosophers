/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:16:16 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/20 12:19:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    ft_create_process(t_philo *philo, int num_philo)
{
    int i;

    i = 0;
    while (i < num_philo)
    {
        philo[i].pid = fork();
        if (philo[i].pid == 0)
        {
            routine(&philo[i]);
            exit(0);
        }
        i++;
    }
}

void    *check_is_dead(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (time_in_ms() - philo->end > philo->time_to_die)
        {
            sem_wait(philo->send);
            printf("\033[0;31m%ld %d died\n\033[0m", \
		        (time_in_ms() - philo->start), philo->id_philo);
            exit(0);
        }
        usleep(100);
    }
}

void    routine(t_philo *philo)
{
    pthread_t   id;

    pthread_create(&id, NULL, &check_is_dead, philo);
    while (1)
    {
        sem_wait(philo->forks);
        ft_forks(philo);
        sem_post(philo->send);
        sem_wait(philo->forks);
        ft_forks(philo);
        sem_post(philo->send);
        ft_eat(philo);
        sem_post(philo->forks);
        ft_sleep(philo);
        ft_think(philo);
    }
}

int main(int ac, char **av)
{
    int     num_philo;
    t_philo *philo;
    int     i;
    int     status;

    if (ac < 5 || ac > 6 || check_is_number(av))
    {
        printf("Arguments error\n");
        exit(1);
    }
    num_philo = ft_atoi(av[1]);
    philo = malloc(num_philo * sizeof(t_philo));
    ft_init_data(philo, ac, av, num_philo);
    while(i < num_philo)
    {
        waitpid(-1, &status, 0);
        if (WEXITSTATUS(status) == 0)
        {
            ft_kill_processors(philo);
            exit(0);
        }
        i++;
    }
    return (0);
}