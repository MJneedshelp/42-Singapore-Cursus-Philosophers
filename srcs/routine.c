/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/12 09:32:38 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	assign_forks(t_philo *me, t_fork *cutlery, int *ctr)
{
	me->p_no = ctr + 1;
	me->r_fork
}












/* Description: The routine function called by each philo thread when each
   thread is created. Performs the following actions:
	1. Initialise a philo struct
	2. XXXX
*/

void	*meal_start(void *data)
{
	pthread_t	tid;
	t_config	*config;
	t_philo		me;

	config = (t_config *)data;

	tid = pthread_self();
	printf("Philo: %ld is alive!!\n", tid);
	if (data == NULL)
		printf("Correct\n");





	return (NULL);
}
