/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:49:46 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 12:35:58 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	no_phil;
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	eat_reps;
	pthread_t	*cust;
}	t_philo;


/* Initialisation */
void	arise_philos(t_philo *philo);





/* Utility functions */
int		ft_atoi(const char *str);





//Probably need a structure that mallocs the number of threads based on input
//Probably need a structure that also mallocs the number of mutexes




#endif



