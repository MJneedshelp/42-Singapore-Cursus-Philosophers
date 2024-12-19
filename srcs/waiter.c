/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:14:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/19 18:09:54 by mintan           ###   ########.fr       */
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
	int				meal_end;
	unsigned int	ctr;
	t_philo			*curr_philo;

	cfg = (t_config *)data;
	meal_end = get_bool(&(cfg->meal_end), &(cfg->mt_cfg));
	ctr = cfg->no_phil - 1;
	while (meal_end != TRUE)
	{
		curr_philo = &(cfg->philos[ctr % cfg->no_phil]);
		if (get_bool(&(curr_philo->full), &(curr_philo->mt_me)) != TRUE)
		{
			if (checktime() - get_long(&(curr_philo->ms_last_eat),
			&(curr_philo->mt_me)) > (long)(cfg->die_ms))
			{
				set_bool(&(cfg->meal_end), TRUE, &(cfg->mt_cfg));
				print_status(ctr % cfg->no_phil, DEAD, curr_philo);
				break;
			}
		}
		else
			cfg->bill[ctr % cfg->no_phil] = TRUE;



		//check if all philos are full as well


		ctr++;
		if (ctr == 0)
			ctr = cfg->no_phil - 1;
	}
	printf("Waiter broke out of while loop\n");
	return (NULL);
}
