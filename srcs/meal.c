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

/* Description: Sequence of events for eating:
	1. Pick up first fork - print status
	2. Pick up second fork - print status
	3. print status: EATING
	4. Update ms_last_eat - locking required since me.ms_last_eat is checked
	   by the waiter
	5. Eat - usleep(ms_eat)
	6. Drop first fork
	7. Drop second fork
	8. Increment eat_times - done outside of lock since this variable is only
	   accessed by me
	9. Set full to TRUE if I have eaten enough - locking required since me.full
	   is checked by the waiter
*/

void	eat(t_philo *me)
{
	long	eat_start;
	long	eat_times;
	int		eat_reps;

	eat_reps = me->cfg->eat_reps;
	pthread_mutex_lock(me->first_fork);
	print_status(me->p_no, GRAB_FIRST_FORK, me);
	pthread_mutex_lock(me->second_fork);
	print_status(me->p_no, GRAB_SECOND_FORK, me);
	eat_start = print_status(me->p_no, EATING, me);
	set_long(&(me->ms_last_eat), eat_start, &(me->mt_me));
	usleep(me->cfg->eat_ms * 1000);
	pthread_mutex_unlock(me->first_fork);
	pthread_mutex_unlock(me->second_fork);
	if (eat_reps != -1)
	{
		eat_times = get_long(&(me->eat_times), &(me->mt_me));
		set_long(&(me->eat_times), eat_times + 1, &(me->mt_me));
		if (eat_times + 1 == eat_reps)
			set_bool(&(me->full), TRUE, &(me->mt_me));
	}
}

/* Description: Prints the sleep status and then usleeps for the sleep time
*/
void	dream(t_philo *me)
{
	print_status(me->p_no, SLEEPING, me);
	usleep(me->cfg->sleep_ms * 1000);
}

/* Description: Prints the thinking status. usleeps for the half the sleep
   time under the following conditions:
	- Odd number of philos AND
	- Eat time == Sleep time OR Eat time > Sleep time
*/
void	wonder(t_philo *me)
{
	print_status(me->p_no, THINKING, me);
	if (me->cfg->no_phil % 2 != 0 && (me->cfg->eat_ms == me->cfg->sleep_ms || \
	me->cfg->eat_ms > me->cfg->sleep_ms))
		usleep(0.5 * me->cfg->sleep_ms * 1000);
}

/* Description: The routine function called by each philo thread when each
   thread is created. Each thread's philo characteristics (philo number, the
   forks the thread has access to, etc.) are passed into the routine function.
   Performs the following actions:
	1. Waits for all philos to be seated at the table
	2. Sets the start time as the last eat time
	3. Sets a condition for the even numbered philos to sleep first
	4. While meal is ongoing:
		a. Check if I am full. Break if full
		b. Eat
		c. Check if I am full. Break if full
		d. Sleep
		e. Think. Thinking time introduced for the following scenarios:
			- Odd number of philos AND
			- Eat time == Sleep time OR Eat time > Sleep time
*/

void	*meal_start(void *data)
{
	t_philo			*me;
	long			time;

	me = (t_philo *)data;
	wait_ready(&(me->cfg->mt_cfg), &(me->cfg->all_seated));
	time = checktime();
	set_long(&(me->ms_last_eat), time, &(me->mt_me));
	if (me->p_no % 2 == 0)
	{
		print_status(me->p_no, SLEEPING, me);
		usleep(me->cfg->sleep_ms * 1000);
		print_status(me->p_no, THINKING, me);
	}
	while (get_bool(&(me->cfg->meal_end), &(me->cfg->mt_cfg)) == FALSE)
	{
		if (get_bool(&(me->full), &(me->mt_me)) == TRUE)
			break ;
		eat(me);
		if (get_bool(&(me->full), &(me->mt_me)) == TRUE)
			break ;
		dream(me);
		wonder(me);
	}
	return (NULL);
}
