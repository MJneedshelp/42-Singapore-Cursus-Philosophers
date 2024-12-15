/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/15 18:16:03 by mintan           ###   ########.fr       */
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
	t_philo			*me;

	struct timeval	t_time;
	int				usec_sleep;

	usec_sleep = 3000000;
	me = (t_philo *)data;

	//implement a while loop with either condition 1 or no. of times eaten in each philo routine
	//1 more thread that just goes around checking if each philo is dead
	//possibly 1 mutex for each member in the philo struct that the waiter and the philo is changing


	// if (gettimeofday(&t_time, NULL) != 0)
	// {
	// 	printf("gettimeofday failed\n");
	// 	//do smth here to handle the case where gettime of day fails
	// 	//update the philo status within the philo struct
	// }
	// printf("%ld %ld is alive!! I am Philo: %d | eat times: %d | cfg addr: %p | r_fork: %d | l_fork: %d\n",
	// t_time.tv_usec, tid, me->p_no, me->eat_times, me->config, me->r_fork, me->l_fork);


	// if (gettimeofday(&t_time, NULL) != 0)
	// {
	// 	printf("gettimeofday failed\n");
	// 	//do smth here to handle the case where gettime of day fails
	// 	//update the philo status within the philo struct
	// }
	// printf("%ld %ld I am Philo: %d | Before forks are picked up\n", t_time.tv_sec, t_time.tv_usec, me->p_no);

	// printf("I am Philo: %d | R_no: %d | R_adr: %p | L_no: %d | L_adr: %p\n", me->p_no, me->r_no, me->r_fork, me->l_no, me->l_fork);


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
