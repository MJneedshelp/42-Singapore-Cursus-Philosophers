/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/10 19:24:14 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Initialises all the input
*/


int	init_config(t_config *config, int argc, char *argv[])
{

	config->no_phil = ft_atoi(argv[1]);
	config->die_ms = ft_atoi(argv[2]);
	config->eat_ms = ft_atoi(argv[3]);
	config->sleep_ms = ft_atoi(argv[4]);
	config->eat_reps = -1;
	if (argc > 5)
		config->eat_reps = ft_atoi(argv[5]);
	config->cust = (pthread_t *)malloc(config->no_phil * sizeof(pthread_t));
	config->cutlery = (t_fork *)malloc(config->no_phil * sizeof(t_fork));
	if (config->cutlery == NULL || config->cust == NULL)
	{
		dishwasher(config);
		exit (EXIT_FAILURE);
	}


	//function to create all the forks first before creating the threads
	//the forks can then be assigned to the philo struct within the routine
	//some way to start tracking the time



	if (arise_philos(config) == EXIT_FAILURE)
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
