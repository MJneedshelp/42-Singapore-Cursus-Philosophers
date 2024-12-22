/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:39:09 by mintan            #+#    #+#             */
/*   Updated: 2024/12/22 13:07:42 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: Uses the gettimeofday function to retrieve the time. Formats
   the results and returns it as a long variable is milliseconds.
*/
long	checktime(void)
{
	long			ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000 + tv.tv_usec / 1000) % 1000000;
	return (ms);
}
