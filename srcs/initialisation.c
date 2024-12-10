/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/11 01:22:33 by mintan           ###   ########.fr       */
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

/* Description: Creates the cutlery
*/

/* Description: Creates the philo threads. If any of the thread creation fails,
   join all the created philos, then free the memory allocated for cust[].
*/

int	arise_philos(t_config *config)
{
	int	i;
	int	status;

	i = 0;
	status = EXIT_SUCCESS;
	while (i < config->no_phil)
	{
		if (pthread_create(&(config->cust[i]), NULL, routine, NULL) != 0)
		{
			ft_putendl_fd("Error creating philos", STDERR_FILENO);
			status = EXIT_FAILURE;
			break ;
		}
		printf("Inside pthread_t: %lu\n", config->cust[i]);
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		join_philos(config->cust, i);
		dishwasher(config);
	}
	return (status);
}

/* Description: Creates the fork structures and store in an aray of forks
*/
int	create_forks(t_config *config)
{
	int	i;
	int	status;

	i = 0;
	status = EXIT_SUCCESS;
	while (i < config->no_phil)
	{
		config->cutlery[i].fork_no = i + 1;
		if (pthread_mutex_init(&(config->cutlery[i].mt_fork), NULL) != 0)
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
		//destroy created mutexes
		dishwasher(config);
	}
	return (status);
}
