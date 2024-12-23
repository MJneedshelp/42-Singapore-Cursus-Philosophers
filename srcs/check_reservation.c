/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reservation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 08:44:02 by mintan            #+#    #+#             */
/*   Updated: 2024/12/23 00:04:50 by mintan           ###   ########.fr       */
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
	else if (type == ERR_TABLE_LIMIT)
	{
		ft_putstr_fd(ERR_TABLE_LIMIT_1, STDERR_FILENO);
		ft_putnbr_fd(MAX_PHILOS, STDERR_FILENO);
		ft_putendl_fd(ERR_TABLE_LIMIT_2, STDERR_FILENO);
	}
	ft_putendl_fd(ERR_EG_1, STDERR_FILENO);
	ft_putendl_fd(ERR_EG_2, STDERR_FILENO);
}

/* Description: handles the case where there is only 1 philo. Prints out the
   required messages without consuming unnecessary resources.
*/

void	lone_customer(char *argv[])
{
	printf(GREEN"%ld " RED"1 has taken a fork\n"RESET, checktime());
	usleep(ft_atoi(argv[2]));
	printf(GREEN"%ld " NORM_WHITE"1 died\n"RESET, checktime());
	if (argv[2] == NULL)
		printf("Correct\n");
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
	3. Accept only between 1 and MAX philos
	4. Handle the case of 1 philo
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
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > MAX_PHILOS)
	{
		print_err(ERR_TABLE_LIMIT);
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		lone_customer(argv);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
