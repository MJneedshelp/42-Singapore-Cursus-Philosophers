/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/21 16:58:45 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Loops through the bill array and checks if all items are TRUE.
   If all philos are full, then return TRUE. Else return FALSE.
*/

int	all_bill(int no_phil, int *bill)
{
	int	i;
	int	status;

	i = 0;
	status = TRUE;
	while (i < no_phil)
	{
		if (bill[i] != TRUE)
		{
			status = FALSE;
			break;
		}
		i++;
	}
	return (status);
}



/* Description: The routine function called by the waiter thread after its
   creation. Cycles through each philo and performs the following:
   	1. Checks if the philo is full already. Skip step 2 if philo is full
	2. Get current time, checks philo's last eat time -> determine if philo is
	   dead
	3. Update the meal_end variable to TRUE if some philo died
	4. If the philo is full, update the index of the philo as full in cfg->bill
	   - No need to mutex lock since this struct member is only touched by the
	   waiter
	5. Check if all bills are TRUE (all philos are full), update the meal_end
	   variable to TRUE
*/

void	*waiter_start(void *data)
{
	t_config		*cfg;
	unsigned int	ctr;
	t_philo			*curr_philo;
	// long			dur;

	usleep(500);
	cfg = (t_config *)data;
	ctr = cfg->no_phil - 1;
	while (get_bool(&(cfg->meal_end), &(cfg->mt_cfg)) != TRUE)
	{
		curr_philo = &(cfg->philos[ctr % cfg->no_phil]);
		if (get_bool(&(curr_philo->full), &(curr_philo->mt_me)) != TRUE)
		{
			// dur = checktime() - get_long(&(curr_philo->ms_last_eat), &(curr_philo->mt_me));
			// printf("Dur: %ld\n", dur);

			if (checktime() - get_long(&(curr_philo->ms_last_eat), \
			&(curr_philo->mt_me)) > (long)(cfg->die_ms))
			// if (dur > (long)(cfg->die_ms))
			{
				print_status((ctr % cfg->no_phil) + 1, DEAD, curr_philo, DEBUG);
				// set_bool(&(cfg->meal_end), TRUE, &(cfg->mt_cfg));
				break;
			}
		}
		else
			cfg->bill[ctr % cfg->no_phil] = TRUE;
		if (all_bill(cfg->no_phil, cfg->bill) == TRUE)
			set_bool(&(cfg->meal_end), TRUE, &(cfg->mt_cfg));
		ctr++;
		if (ctr == 0)
			ctr = cfg->no_phil - 1;
	}
	// printf("Waiter routine finished\n");
	return (NULL);
}
