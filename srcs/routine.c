/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/13 01:34:02 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"





/* Description: The routine function called by each philo thread when each
   thread is created. Performs the following actions:
	1. 
	2. XXXX
*/

void	*meal_start(void *data)
{
	pthread_t	tid;
	t_philo		*me;

	me = (t_philo *)data;

	tid = pthread_self();
	printf("%ld is alive!! I am Philo: %d | eat times: %d | cfg addr: %p | r_fork: %d | l_fork: %d\n",\
	tid, me->p_no, me->eat_times, me->config, me->r_fork, me->l_fork);






	return (NULL);
}
