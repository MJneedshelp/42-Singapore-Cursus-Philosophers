/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:49:46 by mintan            #+#    #+#             */
/*   Updated: 2024/12/12 23:19:41 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Forward declare s_config and s_philo as they will be referencing
   each other */

typedef struct s_config	t_config;
typedef struct s_philo	t_philo;

/* Define s_config struct. Configuration structure to hold all the important
   information*/
typedef struct s_config
{
	int				no_phil;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				eat_reps;
	pthread_t		*cust;
	pthread_mutex_t	*mt_forks;
	t_philo			*philos;
	// int			ctr;
	// t_fork		*cutlery;
	//might need a counter inside that each thread needs to access
	//which also means that this config probably needs a mutex representing the counter
}	t_config;

/* Define the s_philo struct. Contains the characteristics of each philo philo thread
*/
typedef struct s_philo
{
	int			p_no;
	// last_eat_time
	int			r_fork;
	int			l_fork;
	int			eat_times;
	t_config	*config;
}	t_philo;



/* Initialisation */
void	init_philos(t_config *cfg, t_philo *philos, int no_phil);

int		arise_philos(t_config *config);

int		create_forks(t_config *config);



/* Rountine */
void	*meal_start(void *data);




/* Clean-up functions */
void	join_philos(pthread_t *cust, int num);
void	dishwasher(t_config *config);





/* Utility functions */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);









#endif



