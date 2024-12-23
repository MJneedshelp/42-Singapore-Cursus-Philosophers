/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:08:26 by mintan            #+#    #+#             */
/*   Updated: 2024/12/24 05:18:02 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: Printing function used for debugging. Prints out the specific \
   fork number for troubleshooting.
*/

void	print_debug(int p_no, int status, long now)
{
	if (status == GRAB_FIRST_FORK)
		printf(GREEN"%ld " RED"%d picked up 1st fork\n"RESET, now, p_no);
	else if (status == GRAB_SECOND_FORK)
		printf(GREEN"%ld " RED"%d picked up 2nd fork\n"RESET, now, p_no);
	else if (status == EATING)
		printf(GREEN"%ld " WHITE"%d is eating\n"RESET, now, p_no);
	else if (status == SLEEPING)
		printf(GREEN"%ld " BLUE"%d is sleeping\n"RESET, now, p_no);
	else if (status == THINKING)
		printf(GREEN"%ld " YELLOW"%d is thinking\n"RESET, now, p_no);
	else if (status == DEAD)
		printf(GREEN"%ld " NORM_WHITE"%d died\n"RESET, now, p_no);
}

/* Description: Takes in the philo number, the status and the philo struct.
   Checks if the meal has ended. If meal is still ongoing, locks the mt_print
   before printing the status messages. Unlocks mt_print after. Returns the
   timestamp of the printed status
*/

long	print_status(int p_no, int status, t_philo *me)
{
	long	now;
	long	p_now;

	pthread_mutex_lock(&(me->cfg->mt_print));
	now = checktime();
	p_now = now - me->cfg->start_time;
	if (get_bool(&(me->cfg->meal_end), &(me->cfg->mt_cfg)) != TRUE)
	{
		if (status == GRAB_FIRST_FORK || status == GRAB_SECOND_FORK)
			printf(GREEN"%ld " RED"%d has taken a fork\n"RESET, p_now, p_no);
		else if (status == EATING)
			printf(GREEN"%ld " WHITE"%d is eating\n"RESET, p_now, p_no);
		else if (status == SLEEPING)
			printf(GREEN"%ld " BLUE"%d is sleeping\n"RESET, p_now, p_no);
		else if (status == THINKING)
			printf(GREEN"%ld " YELLOW"%d is thinking\n"RESET, p_now, p_no);
		else if (status == DEAD)
		{
			set_bool(&(me->cfg->meal_end), TRUE, &(me->cfg->mt_cfg));
			printf(GREEN"%ld " NORM_WHITE"%d died\n"RESET, p_now, p_no);
		}
	}
	pthread_mutex_unlock(&(me->cfg->mt_print));
	return (now);
}
