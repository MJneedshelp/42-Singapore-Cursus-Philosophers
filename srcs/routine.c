/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/15 12:15:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"





/* Description: The routine function called by each philo thread when each
   thread is created. Each thread's philo characteristics (philo number, the
   forks the thread has access to, etc.) are passed into the routine function.
   Performs the following actions:
	1. Each
	2. XXXX
*/

void	*meal_start(void *data)
{
	pthread_t		tid;
	t_philo			*me;
	struct timeval	t_start;

	me = (t_philo *)data;

	tid = pthread_self();
	if (gettimeofday(&t_start, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		//do smth here to handle the case where gettime of day fails
		//update the philo status within the philo struct
	}
	printf("%ld %ld is alive!! I am Philo: %d | eat times: %d | cfg addr: %p | r_fork: %d | l_fork: %d\n",\
	t_start.tv_usec, tid, me->p_no, me->eat_times, me->config, me->r_fork, me->l_fork);






	return (NULL);
}
