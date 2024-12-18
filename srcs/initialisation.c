/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/18 22:39:18 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Iterates through an array of philos and assigns an order to the
   forks based on the philo number:
	- Even philo:
		- first: right fork
		- second: left fork
	- Odd philo:
		- first: left fork
		- second: right fork
*/

void	assign_forks(t_philo *philos, int no_phil)
{
	int	i;

	i = 0;
	while (i < no_phil)
	{
		if (philos[i].p_no % 2 == 0)
		{
			philos[i].first_fork = philos[i].r_fork;
			philos[i].second_fork = philos[i].l_fork;
		}
		else
		{
			philos[i].first_fork = philos[i].l_fork;
			philos[i].second_fork = philos[i].r_fork;
		}
		i++;
	}
}

/* Description: Initialises the members of the philo array for each philo in
   the array of philos. Assigns the following
   XXXXXXXXXXXXXXXXXX fill in later
*/
int	init_philos(t_config *cfg, t_philo *philos, int no_phil)
{
	int	i;

	i = 0;
	while (i < no_phil)
	{
		printf("Inside init philos. Philo number: %d | address: %p\n", i + 1, &philos[i]);

		philos[i].cfg = cfg;
		philos[i].eat_times = 0;
		philos[i].p_no = i + 1;
		philos[i].r_no = i;
		philos[i].r_fork = &(cfg->mt_forks[i]);
		philos[i].full = FALSE;
		if (i == 0)
		{
			philos[i].l_fork = &(cfg->mt_forks[no_phil - 1]);
			philos[i].l_no = no_phil - 1;
		}
		else
		{
			philos[i].l_fork = &(cfg->mt_forks[i - 1]);
			philos[i].l_no = i - 1;
		}
		i++;
	}
	assign_forks(philos, no_phil);
	if (mutex_init(&(philos[i].mt_me)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		destroy_mutex_array(mt_forks, i);
		dishwasher(cfg);
	}
	return (status);
}
