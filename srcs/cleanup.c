/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:05:55 by mintan            #+#    #+#             */
/*   Updated: 2024/12/20 01:10:45 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Frees all the memory allocated in the config data structure.
   Members to free (SO FAR):
	- cfg->bill
	- cfg->cust
	- cfg->mt_forks
	- cfg->philos
*/
void	dishwasher(t_config *cfg)
{
	if (cfg->bill != NULL)
		free (cfg->bill);
	if (cfg->cust != NULL)
		free (cfg->cust);
	if (cfg->mt_forks != NULL)
		free (cfg->mt_forks);
	if (cfg->philos != NULL)
		free (cfg->philos);
	cfg->bill = NULL;
	cfg->cust = NULL;
	cfg->mt_forks = NULL;
	cfg->philos = NULL;
}

/* Description: joins all the created philo threads. This function is used
   at the start during the thread creation, when pthread_create fails, or
   at the end of the programme. Breaks out of the loop if thread_join fails
*/

void	join_philos(pthread_t *cust, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(cust[i], NULL) != 0)
			break ;
		i++;
	}
}

/* Description: Takes in a number and an array of pthread_mutex_t objects.
   Iterates n times through the array of pthread_mutex_t objects and destroys
   each mutex object.
*/
void	destroy_forks_mutex(pthread_mutex_t *mt_arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&(mt_arr[i]));
		i++;
	}
}

/* Description: Destroys the mutex in each of of the philo structures.
*/

void	destroy_philo_mutex(t_philo *philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&(philos[i].mt_me));
		i++;
	}
}

/* Description: Destroys all the mutex used in the programme:
	1. Destroys all the fork mutex
	2. Destroys all the philo mutex
	3. Destroys mt_cfg
	4. Destroys mt_print
*/

void	destroy_all_mutex(t_config *cfg)
{
	destroy_forks_mutex(cfg->mt_forks, cfg->no_phil);
	destroy_philo_mutex(cfg->philos, cfg->no_phil);
	pthread_mutex_destroy(&(cfg->mt_cfg));
	pthread_mutex_destroy(&(cfg->mt_print));
}
