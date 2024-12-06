/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 17:30:51 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Initialises all the input
*/


int	init_config(t_config *philo, int argc, char *argv[])
{
	philo->no_phil = ft_atoi(argv[1]);
	philo->die_ms = ft_atoi(argv[2]);
	philo->eat_ms = ft_atoi(argv[3]);
	philo->sleep_ms = ft_atoi(argv[4]);
	philo->eat_reps = -1;
	if (argc > 5)
		philo->eat_reps = ft_atoi(argv[5]);
	philo->cust = (pthread_t *)malloc(philo->no_phil * sizeof(pthread_t));
	if (philo->cust == NULL)
		exit (EXIT_FAILURE);
	if (arise_philos(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}






int	main(int argc, char *argv[])
{
	t_config	config;

	//Perfom input validation here first before initialisation
	if (init_config(&config, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);


	sleep(5);
	printf("philo number: %d | die time: %d | eat time: %d | sleep time: %d | eat reps: %d\n", config.no_phil, config.die_ms, config.eat_ms, config.sleep_ms, config.eat_ms);








	join_philos(config.cust, config.no_phil);
	free (config.cust);



	return (EXIT_SUCCESS);




}


/*
	to do:
		- validation for the input arguments

*/
