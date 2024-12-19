/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:08:26 by mintan            #+#    #+#             */
/*   Updated: 2024/12/20 02:18:39 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: Printing function used for debugging. Prints out the specific \
   fork number for troubleshooting.
*/

void	print_debug(int p_no, int status, t_philo *me, long now)
{
	pthread_mutex_lock(&(me->cfg->mt_print));
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
	pthread_mutex_unlock(&(me->cfg->mt_print));
}

/* Description: Takes in the philo number, the status and the philo struct.
   Checks if the meal has ended. If meal is still ongoing, locks the mt_print
   before printing the status messages. Unlocks mt_print after. Returns the
   timestamp of the printed status
*/

long	print_status(int p_no, int status, t_philo *me, int debug)
{
	long	now;

	now = checktime();
	if (get_bool(&(me->cfg->meal_end), &(me->cfg->mt_cfg)) != TRUE)
	{
		if (debug == TRUE)
			print_debug(p_no, status, me, now);
		else
		{
			pthread_mutex_lock(&(me->cfg->mt_print));
			if (status == GRAB_FIRST_FORK || status == GRAB_SECOND_FORK)
				printf(GREEN"%ld " RED"%d has taken a fork\n"RESET, now, p_no);
			else if (status == EATING)
				printf(GREEN"%ld " WHITE"%d is eating\n"RESET, now, p_no);
			else if (status == SLEEPING)
				printf(GREEN"%ld " BLUE"%d is sleeping\n"RESET, now, p_no);
			else if (status == THINKING)
				printf(GREEN"%ld " YELLOW"%d is thinking\n"RESET, now, p_no);
			else if (status == DEAD)
				printf(GREEN"%ld " NORM_WHITE"%d died\n"RESET, now, p_no);
			pthread_mutex_unlock(&(me->cfg->mt_print));
		}
	}
	return (now);
}
