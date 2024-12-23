/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:55:36 by mintan            #+#    #+#             */
/*   Updated: 2024/12/21 08:51:40 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: takes in a character to check if it is a digit.
   	- if it is a numeric character, return non-zero
	- else, return 0
*/

int	ft_isdigit(int a)
{
	if ((a >= '0' && a <= '9'))
		return (1);
	return (0);
}
