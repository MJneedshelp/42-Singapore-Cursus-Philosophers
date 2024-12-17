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
   the variable after.
*/

int	set_bool(int *bool, int bool_val, pthread_mutex_t *mt)
{
	int	status;

	status = EXIT_SUCCESS;
	if (pthread_mutex_lock(mt) != 0)
		return (EXIT_FAILURE);
	*bool = bool_val;
	if (pthread_mutex_unlock(mt) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
