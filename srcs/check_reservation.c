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

/* Description: prints the error message for wrong number of arguments */
void	print_err_no_arg(void)
{
	ft_putstr_fd(ERR_NO_ARG_1, STDERR_FILENO);
	ft_putstr_fd(ERR_NO_ARG_2, STDERR_FILENO);
	ft_putendl_fd(ERR_NO_ARG_3, STDERR_FILENO);
	ft_putendl_fd(ERR_NO_ARG_4, STDERR_FILENO);
	ft_putendl_fd(ERR_NO_ARG_5, STDERR_FILENO);
}


	/* Description: Takes in a string and checks if all characters are digits.
   - Allows for ' ', '\t', '\r', at the start of the string.
   - Allows for either 1 '+' or '-' after the spaces, before the digits
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
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}


// things to check for
// correct number of arguments
// check digits
// might wanna check max number of threads created

int	input_validation(int argc, char *argv[])
{
	if (argc != 5 || argc != 6)
	{
		print_err_no_arg();
		return (EXIT_FAILURE);
	}
	while (argc > 1)
	{
		if (check_numeric(argv[argc - 1]) == FALSE)
		{
			print_err_no_arg();
			return (EXIT_FAILURE);
		}




	}
	if (argv[0] == NULL)
		printf("test");
	return (EXIT_SUCCESS);
}
