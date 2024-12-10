/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:05:55 by mintan            #+#    #+#             */
/*   Updated: 2024/12/10 19:20:19 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Frees all the memory allocated in the config data structure.
   Members to free (SO FAR):
	- config->cust
	- config->cutlery
*/
void	dishwasher(t_config *config)
{
	if (config->cust != NULL)
		free (config->cust);
	if (config->cutlery != NULL)
		free (config->cutlery);
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
