/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:30:53 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 15:06:24 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* Description: Outputs the character 'c' to the given file descriptor.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
