/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/20 03:23:13 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Main function of the programme
*/

int	main(int argc, char *argv[])
{
	t_config	cfg;
	pthread_t	waiter;

	//Perfom input validation here first before initialisation


	if (init_config(&cfg, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	//create all the threads
	if (arise_philos(&cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);



	//set all_philos_seated to TRUE -> rmb to lock mutex and unlock mutex
	//all the other philos will be checking this var in the cfg
	set_bool(&(cfg.all_seated), TRUE, &cfg.mt_cfg);


	pthread_create(&waiter, NULL, waiter_start, &cfg); //create waiter thread, check if creation fails
	pthread_join(waiter, NULL);
	join_philos(cfg.cust, cfg.no_phil);
	destroy_all_mutex(&cfg);
	dishwasher(&cfg);
	return (EXIT_SUCCESS);
}


/*
	to do:
		- validation for the input arguments

*/
