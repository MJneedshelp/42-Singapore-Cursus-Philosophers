/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:49:46 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 17:07:54 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Definitions */
// # define SUCCESS 0
// # define ERROR 1



//Probably need a structure that also mallocs the number of mutexes
//Think abt structure for each philo


typedef struct s_config
{
	int	no_phil;
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	eat_reps;
	pthread_t	*cust;
}	t_config;


/* Initialisation */
int		arise_philos(t_config *config);





/* Clean-up functions */
void	join_philos(pthread_t *cust, int num);




/* Utility functions */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);









#endif



