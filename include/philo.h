/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:49:46 by mintan            #+#    #+#             */
/*   Updated: 2024/12/15 12:13:48 by mintan           ###   ########.fr       */
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



enum	e_state
{
	EAT,
	THINK,
	SLEEP
};



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
}	t_config;

/* Define the s_philo struct. Contains the characteristics of each philo philo thread
*/
typedef struct s_philo
{
	int			p_no;
	// last_eat_time
	int			r_fork;
	int			l_fork;
	int			state;
	int			eat_times;
	int			exit_status;	//update the status here to pass the information back out to the main thread to handle
	t_config	*config;
}	t_philo;



/* Initialisation */
void	init_philos(t_config *cfg, t_philo *philos, int no_phil);
int		arise_philos(t_config *cfg);
int		create_forks(t_config *cfg, pthread_mutex_t *mt_forks, int no_phil);



/* Rountine */
void	*meal_start(void *data);




/* Clean-up functions */
void	join_philos(pthread_t *cust, int num);
void	destroy_mutex_array(pthread_mutex_t *mt_arr, int n);
void	dishwasher(t_config *config);





/* Utility functions */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);









#endif



