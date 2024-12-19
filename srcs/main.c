/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/19 06:04:49 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Sets the all_philos_seated member to TRUE
*/




/* Description: Initialises all the input
   XXXXX EXPLAIN ALL THE DIFFERENT MEMBERS IN YOUR STRUCT PLS
*/


int	init_config(t_config *cfg, int argc, char *argv[])
{

	cfg->no_phil = ft_atoi(argv[1]);
	cfg->die_ms = ft_atoi(argv[2]);
	cfg->eat_ms = ft_atoi(argv[3]);
	cfg->sleep_ms = ft_atoi(argv[4]);
	cfg->eat_reps = -1;
	if (argc > 5)
		cfg->eat_reps = ft_atoi(argv[5]);

	cfg->all_seated = FALSE;
	cfg->meal_end = FALSE;

	if (mutex_init(&(cfg->mt_cfg)) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	cfg->cust = (pthread_t *)malloc(cfg->no_phil * sizeof(pthread_t));
	cfg->mt_forks = (pthread_mutex_t *)malloc(cfg->no_phil * sizeof(pthread_mutex_t));
	cfg->philos = (t_philo *)malloc(cfg->no_phil * sizeof(t_philo));
	if (cfg->mt_forks == NULL || cfg->cust == NULL || cfg->philos == NULL)
	{
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	if (init_philos(cfg, cfg->philos, cfg->no_phil) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_forks(cfg, cfg->mt_forks, cfg->no_phil) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}




int	main(int argc, char *argv[])
{
	t_config	cfg;
	pthread_t	waiter;

	long		test;

	//Perfom input validation here first before initialisation

	// setup functions for getting and settiung mutexes

	test = checktime();
	printf("Outside check: %ld\n", test);




	if (init_config(&cfg, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	//create all the threads
	if (arise_philos(&cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);



	//set all_philos_seated to TRUE -> rmb to lock mutex and unlock mutex
	//all the other philos will be checking this var in the cfg
	set_bool(&(cfg.all_seated), TRUE, &cfg.mt_cfg);

	usleep(1500000);

	pthread_create(&waiter, NULL, waiter_start, &cfg); //create waiter thread, check if creation fails
















	join_philos(cfg.cust, cfg.no_phil);
	//join waiter back
	dishwasher(&cfg);



	return (EXIT_SUCCESS);




}


/*
	to do:
		- validation for the input arguments

*/
