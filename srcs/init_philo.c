/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 12:32:30 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *data)
{
	pthread_t	tid;

	tid = pthread_self();
	printf("Philo: %ld is alive!!\n", tid);
	if (data == NULL)
		printf("Correct\n");
	return (NULL);
}





void	arise_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->no_phil)
	{
		if (pthread_create(&(philo->cust[i]), NULL, routine, NULL) != 0)
		{
			perror("Philos are not alive\n");
			//free memory up to this point
			exit (EXIT_FAILURE);
		}
		i++;
	}
}


