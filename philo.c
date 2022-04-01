/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:38 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/01 16:17:51 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TO DO when we have 6 arguments i.e number of times each philo eats (meal_optional())

int main(int ac, char **av)
{
    int         num_philo;
    t_philo     *philo;
    pthread_t   id;

    if(ac < 5 || ac > 6 || check_is_number(av))
    {
        printf("Arguments error\n");
        exit(1);
    }
    num_philo = ft_atoi(av[1]);
    philo = malloc(num_philo * sizeof(t_philo));
    if(ac == 6)
    {
        pthread_create(&id, NULL, &meal_optional, philo);
        if(pthread_join(id, NULL) == 0)
            return (0);
    }
    while(1)
    {
        if(!ft_check_is_death(philo, num_philo))
            return (0);
    }
}