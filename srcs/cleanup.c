/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:05:55 by mintan            #+#    #+#             */
/*   Updated: 2024/12/12 23:21:02 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Frees all the memory allocated in the config data structure.
   Members to free (SO FAR):
	- cfg->cust
	- cfg->mt_forks
	- cfg->philos
*/
void	dishwasher(t_config *cfg)
{
	if (cfg->cust != NULL)
		free (cfg->cust);
	if (cfg->mt_forks != NULL)
		free (cfg->mt_forks);
	if (cfg->philos != NULL)
		free (cfg->philos);
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
