/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 17:11:30 by mintan           ###   ########.fr       */
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
		free(config->cust);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
