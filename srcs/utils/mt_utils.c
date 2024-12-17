/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:08:26 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 11:51:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: Mutex lock a variable and sets it as TRUE / FALSE. Unlocks the
   the variable after. Returns EXIT_FAILURE if any of the mutex functions
   fails.
*/

int	set_bool(int *bool, int bool_val, pthread_mutex_t *mt)
{
	if (pthread_mutex_lock(mt) != 0)
		return (EXIT_FAILURE);
	*bool = bool_val;
	if (pthread_mutex_unlock(mt) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* Description: Mutex lock a variable and reads it. Unlocks the the variable
   after. Returns the read value. If any of the mutex functions fail, return
   EXIT_FAILURE.
*/

int	get_bool(int *bool, pthread_mutex_t *mt)
{
	int	ret;

	if (pthread_mutex_lock(mt) != 0)
		return (EXIT_FAILURE);
	ret = *bool;
	if (pthread_mutex_unlock(mt) != 0)
		return (EXIT_FAILURE);
	return (ret);
}

/* Description: Creates a mutex with pthread_mutex_init. Returns EXIT_FAILURE
   if the pthread_mutex_init function fails
*/
int	mutex_init(pthread_mutex_t *mt)
{
	if (pthread_mutex_init(mt, NULL) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
