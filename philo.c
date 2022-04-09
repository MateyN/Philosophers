/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:38 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/09 15:24:37 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *meal_optional(void *arg)
{
    int i;
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        i = 0;
        while (i < philo[i].num_philo)
        {
            if (time_in_ms() - philo[i].end > philo[i].time_to_die)
            {
                ft_is_dead(&(philo[i]));
                destroy_mutexes(philo->num_philo, philo->forks, philo->send);
                return (0);
            }
            if (philo[i].count_meals < philo[i].meal_opt)
                break;
            if (i == philo[i].num_philo - 1)
            {
                destroy_mutexes(philo->num_philo, philo->forks, philo->send);
                return(NULL);
            }
            i++;
        }
    }
}

int main(int ac, char **av)
{
    int         num_philo;
    t_philo     *philo;
    pthread_t   id;

    if (ac < 5 || ac > 6 || check_is_number(av))
    {
        printf("Arguments error\n");
        exit(1);
    }
    num_philo = ft_atoi(av[1]);
    philo = malloc(num_philo * sizeof(t_philo));
    ft_init_data(philo, ac, av, num_philo);
    if (ac == 6)
    {
        pthread_create(&id, NULL, &meal_optional, philo);
        if (pthread_join(id, NULL) == 0)
            return (0);
    }
    while (1)
    {
        if (!ft_check_is_death(philo, num_philo))
            return (0);
    }
    free(philo);
}
