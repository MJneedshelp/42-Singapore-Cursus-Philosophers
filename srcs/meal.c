/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/16 03:41:40 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Runs a spin lock to check if all the philos are seated at the
   table. Lock and unlock the cfg mutex when reading all_seated.
*/
void	wait_ready(pthread_mutex_t *mt_cfg, int *all_seated)
{
	while (get_bool(all_seated, mt_cfg) != TRUE)
		;
}



/* Description: The routine function called by each philo thread when each
   thread is created. Each thread's philo characteristics (philo number, the
   forks the thread has access to, etc.) are passed into the routine function.
   Performs the following actions:
	1. Waits for all philos to be seated at the table
	2. XXXX
*/

void	*meal_start(void *data)
{
	t_philo			*me;

	struct timeval	t_time;				//delete later
	int				usec_sleep;			//delete later

	me = (t_philo *)data;
	wait_ready(&(me->cfg->mt_cfg), &(me->cfg->all_seated));
	

	// set the ms_last_eat


	//implement a while loop with either condition 1 or no. of times eaten in each philo routine
	//1 more thread that just goes around checking if each philo is dead
	//possibly 1 mutex for each member in the philo struct that the waiter and the philo is changing





	if (pthread_mutex_lock(me->r_fork) != 0)
		printf("p no: %d | Failed to pick up right fork: %d\n", me->p_no, me->r_no);

	if (gettimeofday(&t_time, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		//do smth here to handle the case where gettime of day fails
		//update the philo status within the philo struct
	}
	printf("%ld %ld I am Philo: %d | picked up the r_fork: %d\n", t_time.tv_sec, t_time.tv_usec, me->p_no, me->r_no);

	if (pthread_mutex_lock(me->l_fork) != 0)
		printf("p no: %d | Failed to pick up left fork: %d\n", me->p_no, me->l_no);

	if (gettimeofday(&t_time, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		//do smth here to handle the case where gettime of day fails
		//update the philo status within the philo struct
	}
	printf("%ld %ld I am Philo: %d | picked up the l_fork: %d\n", t_time.tv_sec, t_time.tv_usec, me->p_no, me->l_no);

	usleep(usec_sleep);

	pthread_mutex_unlock(me->l_fork);
	pthread_mutex_unlock(me->r_fork);

	if (gettimeofday(&t_time, NULL) != 0)
	{
		printf("gettimeofday failed\n");
		//do smth here to handle the case where gettime of day fails
		//update the philo status within the philo struct
	}
	printf("%ld %ld I am Philo: %d | slept for usec: %d | unlocked both locks\n", t_time.tv_sec, t_time.tv_usec, me->p_no, usec_sleep);







	return (NULL);
}
