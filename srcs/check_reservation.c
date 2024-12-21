/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reservation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 08:44:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/21 08:44:16 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: prints different types of error messages and prints an example
   for the user at the end
*/
void	print_err(int type)
{
	if (type == ERR_NO_ARGS)
	{
		ft_putstr_fd(ERR_NO_ARG_1, STDERR_FILENO);
		ft_putstr_fd(ERR_NO_ARG_2, STDERR_FILENO);
		ft_putendl_fd(ERR_NO_ARG_3, STDERR_FILENO);
	}
	else if (type == ERR_ARG_NUMERIC)
		ft_putendl_fd(ERR_ARG_NUMERIC_1, STDERR_FILENO);
	ft_putendl_fd(ERR_EG_1, STDERR_FILENO);
	ft_putendl_fd(ERR_EG_2, STDERR_FILENO);
}

/* Description: Takes in a string and checks if all characters are digits.
- Allows for ' ', '\t', '\r', at the start of the string.
- return:
	- TRUE: the string is numeric
	- FALSE: the string is not numeric
*/

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/* Description: performs input validation. Checks the following:
	1. Correct number of arguments: 5 or 6
	2. Each argument is are digits
	3. Handle case of 1 philo
	4. Max threads??
*/

int	input_validation(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		print_err(ERR_NO_ARGS);
		return (EXIT_FAILURE);
	}
	while (argc > 1)
	{
		if (check_numeric(argv[argc - 1]) == FALSE)
		{
			print_err(ERR_ARG_NUMERIC);
			return (EXIT_FAILURE);
		}
		argc--;
	}
	return (EXIT_SUCCESS);
}
