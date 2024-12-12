/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/12 23:35:52 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	cfg->cust = (pthread_t *)malloc(cfg->no_phil * sizeof(pthread_t));
	cfg->mt_forks = (pthread_mutex_t *)malloc(cfg->no_phil * sizeof(pthread_mutex_t));
	cfg->philos = (t_philo *)malloc(cfg->no_phil * sizeof(t_philo));
	if (cfg->mt_forks == NULL || cfg->cust == NULL || cfg->philos == NULL)
	{
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	init_philos(cfg, cfg->philos, cfg->no_phil);




	// if (create_forks(cfg) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);


	//function to create all the forks first before creating the threads
	//the forks can then be assigned to the philo struct within the routine
	//some way to start tracking the time



	// if (arise_philos(cfg) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}






int	main(int argc, char *argv[])
{
	t_config	cfg;

	int			i;

	//Perfom input validation here first before initialisation





	if (init_config(&cfg, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	printf("Address of config: %p\n", &cfg);
	i = 0;
	while (i < cfg.no_phil)
	{
		printf("Philo: %d | eat times: %d | cfg addr: %p | r_fork: %d | l_fork: %d\n", \
		(&cfg.philos[i])->p_no, (&cfg.philos[i])->eat_times, (&cfg.philos[i])->config, (&cfg.philos[i])->r_fork, (&cfg.philos[i])->l_fork);
		i++;
	}


	sleep(5);
	printf("philo number: %d | die time: %d | eat time: %d | sleep time: %d | eat reps: %d\n", cfg.no_phil, cfg.die_ms, cfg.eat_ms, cfg.sleep_ms, cfg.eat_ms);








	join_philos(cfg.cust, cfg.no_phil);
	dishwasher(&cfg);



	return (EXIT_SUCCESS);




}


/*
	to do:
		- validation for the input arguments

*/
