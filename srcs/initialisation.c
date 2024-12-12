/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/13 01:32:09 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// REMOVE LATER
void	*routine(void *data)
{
	pthread_t	tid;

	tid = pthread_self();
	printf("Philo: %ld is alive!!\n", tid);
	if (data == NULL)
		printf("Correct\n");
	return (NULL);
}

/* Description: Initialises the members of the philo array for each philo in
   the array of philos. Assigns the following
*/
void	init_philos(t_config *cfg, t_philo *philos, int no_phil)
{
	int	i;

	i = 0;
	while (i < no_phil)
	{
		philos[i].config = cfg;
		philos[i].eat_times = 0;
		philos[i].p_no = i + 1;
		philos[i].r_fork = i;
		if (i == 0)
			philos[i].l_fork = no_phil - 1;
		else
			philos[i].l_fork = i - 1;
		i++;
	}
}







/* Description: Creates the philo threads. If any of the thread creation fails,
   join all the created philos, then free the memory allocated for cust[].
*/

int	arise_philos(t_config *cfg)
{
	int	i;
	int	status;

	i = 0;
	status = EXIT_SUCCESS;
	while (i < cfg->no_phil)
	{
		if (pthread_create(&(cfg->cust[i]), NULL, meal_start, &(cfg->philos[i])) != 0)
		{
			ft_putendl_fd("Error creating philos", STDERR_FILENO);
			status = EXIT_FAILURE;
			break ;
		}
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		join_philos(cfg->cust, i);
		dishwasher(cfg);
	}
	return (status);
}

/* Description: Creates an array of mutex objects where each mutex represents
   a fork. If there are errors encountered uring the mutex creation, destroy
   the previously created mutex.
*/
int	create_forks(t_config *cfg, pthread_mutex_t *mt_forks, int no_phil)
{
	int	i;
	int	status;

	i = 0;
	status = EXIT_SUCCESS;
	while (i < no_phil)
	{
		if (pthread_mutex_init(&(mt_forks[i]), NULL) != 0)
		{
			ft_putendl_fd("Error creating forks", STDERR_FILENO);
			status = EXIT_FAILURE;
			break;
		}
		printf("Created fork: %d\n", i + 1);
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		destroy_mutex_array(mt_forks, i);
		dishwasher(cfg);
	}
	return (status);
}
