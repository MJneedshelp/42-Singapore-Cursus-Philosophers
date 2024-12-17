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

/* Description: Mutex lock an int variable and sets it as TRUE / FALSE. Unlocks
   the the variable after.
*/

void	set_bool(int *bool, int bool_val, pthread_mutex_t *mt)
{
	pthread_mutex_lock(mt);
	*bool = bool_val;
	pthread_mutex_unlock(mt);
}

/* Description: Mutex lock an int variable and reads it. Unlocks the the
   variable after. Returns the read value.
*/

int	get_bool(int *bool, pthread_mutex_t *mt)
{
	int	ret;

	pthread_mutex_lock(mt);
	ret = *bool;
	pthread_mutex_unlock(mt);
	return (ret);
}

/* Description: Mutex lock a long variable and sets it to the long value passed
   in. Unlocks the variable after.
*/

void	set_long(long *l_nbr, long long_val, pthread_mutex_t *mt)
{
	pthread_mutex_lock(mt);
	*l_nbr = long_val;
	pthread_mutex_unlock(mt);
}

/* Description: Mutex lock a long variable and reads it. Unlocks the the
   variable after. Returns the read value.
*/

int	get_long(long *l_nbr, pthread_mutex_t *mt)
{
	long	ret;

	pthread_mutex_lock(mt);
	ret = *l_nbr;
	pthread_mutex_unlock(mt);
	return (ret);
}

/* Description: Creates a mutex with pthread_mutex_init. Returns EXIT_FAILURE
   if the pthread_mutex_init function fails
*/
int	mutex_init(pthread_mutex_t *mt)
{
	if (pthread_mutex_init(mt, NULL) != 0)
	{
		ft_putendl_fd("Error initialising mutex", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
