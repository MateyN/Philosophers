/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:38:05 by mnikolov          #+#    #+#             */
/*   Updated: 2022/04/01 15:52:17 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int ft_atoi(const char *str)
{
    int             i;
    long long int   n;
    int             sign;

    i = 0;
    n = 0;
    sign = 1;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

int check_is_number(char **av)
{
    int i;

    i = 1;
    while(av[i])
    {
        if(ft_atoi(av[i]) <= 0)
            return (1);
        i++;
    }
    return (0);
}