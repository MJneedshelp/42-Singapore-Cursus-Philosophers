/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/18 23:43:18 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: The routine function called by the waiter thread after its
   creation. Cycles through each philo and performs the following:
   	1. Get current time, checks philo's last eat time -> determin if philo is
	   dead
	2. Update the meal_end variable to TRUE if some philo died
*/

void	*waiter_start(void *data)
{
	t_config		*cfg;
	int				meal_end;
	unsigned int	ctr;
	t_philo			*curr_philo;

	cfg = (t_config *)data;
	meal_end = get_bool(&(cfg->meal_end), &(cfg->mt_cfg));
	ctr = cfg->no_phil - 1;
	while (meal_end != TRUE)
	{
		curr_philo = &(cfg->philos[ctr % cfg->no_phil]);
		if (checktime() - get_long(&(curr_philo->ms_last_eat),
		&(curr_philo->mt_me)) > (long)(cfg->die_ms))
		{
			set_bool(&(cfg->meal_end), TRUE, &(cfg->mt_cfg));
			break;
		}
		ctr++;
		if (ctr == 0)
			ctr = cfg->no_phil - 1;
	}
	return (NULL);
}
