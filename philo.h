/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:28:44 by mnikolov          #+#    #+#             */
/*   Updated: 2022/03/29 16:02:57 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct  s_philo
{
    pthread_t       id_thread;
    pthread_mutex_t *forks;
    pthread_mutex_t *message;
    int             time_to_die;
    int             time_to_sleep;
    int             time_to_eat;
}   t_philo;



#endif