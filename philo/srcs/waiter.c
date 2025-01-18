/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2025/01/18 15:08:16 by mintan           ###   ########.fr       */
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
			break ;
		}
		i++;
	}
	return (status);
}

/* Description: Checks if the current philo is dead based on their last eat
   time if the philo is not already full. Update meal_end as true in
   print_status function. If the philo is full, bill them.
*/

int	check_dead(t_philo *curr_philo, t_config *cfg, unsigned int ctr)
{
	if (get_bool(&(curr_philo->full), &(curr_philo->mt_me)) != TRUE)
	{
		if (checktime() - get_long(&(curr_philo->ms_last_eat), \
		&(curr_philo->mt_me)) > (long)(cfg->die_ms))
		{
			print_status((ctr % cfg->no_phil) + 1, DEAD, curr_philo);
			return (TRUE);
		}
	}
	else
		cfg->bill[ctr % cfg->no_phil] = TRUE;
	return (FALSE);
}

/* Description: The routine function called by the waiter thread after its
   creation. Cycles through each philo and performs the following:
   	0. Waiter waits for a short delay before checking to allow the philos to
	   set their last eat time
	1. Checks if the philo is full already. Skip step 2 if philo is full
	2. Get current time, checks philo's last eat time -> determine if philo is
	   dead
	3. Update the meal_end variable to TRUE if some philo within the check_dead
	   function
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

	usleep(WAITER_WAIT);
	cfg = (t_config *)data;
	ctr = cfg->no_phil - 1;
	while (get_bool(&(cfg->meal_end), &(cfg->mt_cfg)) != TRUE)
	{
		curr_philo = &(cfg->philos[ctr % cfg->no_phil]);
		if (check_dead(curr_philo, cfg, ctr) == TRUE)
			break ;
		if (all_bill(cfg->no_phil, cfg->bill) == TRUE)
			set_bool(&(cfg->meal_end), TRUE, &(cfg->mt_cfg));
		ctr++;
		if (ctr == 0)
			ctr = cfg->no_phil - 1;
	}
	return (NULL);
}
