/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/12 23:20:45 by mintan           ###   ########.fr       */
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
		if (pthread_create(&(cfg->cust[i]), NULL, routine, NULL) != 0)
		{
			ft_putendl_fd("Error creating philos", STDERR_FILENO);
			status = EXIT_FAILURE;
			break ;
		}
		printf("Inside pthread_t: %lu\n", cfg->cust[i]);
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		join_philos(cfg->cust, i);
		dishwasher(cfg);
	}
	return (status);
}

/* Description: Creates the fork structures and store in an aray of forks
*/
// int	create_forks(t_config *cfg)
// {
// 	int	i;
// 	int	status;

// 	i = 0;
// 	status = EXIT_SUCCESS;
// 	while (i < cfg->no_phil)
// 	{
// 		config->cutlery[i].fork_no = i + 1;
// 		if (pthread_mutex_init(&(config->cutlery[i].mt_fork), NULL) != 0)
// 		{
// 			ft_putendl_fd("Error creating forks", STDERR_FILENO);
// 			status = EXIT_FAILURE;
// 			break;
// 		}
// 		printf("Created fork: %d\n", i + 1);
// 		i++;
// 	}
// 	if (status != EXIT_SUCCESS)
// 	{
// 		//destroy created mutexes
// 		dishwasher(config);
// 	}
// 	return (status);
// }
