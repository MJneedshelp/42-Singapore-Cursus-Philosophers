/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/17 13:50:49 by mintan           ###   ########.fr       */
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

	cfg = (t_config *)data;
	meal_end = get_bool(&(cfg->meal_end), &(cfg->mt_cfg)); //decide if you want to handle mutex lock failures
	ctr = cfg->no_phil - 1;
	while (meal_end != TRUE)
	{
		//check through philo[ctr]
		//if philo dead, set meal end to true
		ctr++;
		if (ctr == 0)
			ctr = cfg->no_phil - 1;
	}



	return (NULL);
}
