/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/15 15:59:48 by mintan           ###   ########.fr       */
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
	if (create_forks(cfg, cfg->mt_forks, cfg->no_phil) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (arise_philos(cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);


	//some way to start tracking the time




	return (EXIT_SUCCESS);
}




int	main(int argc, char *argv[])
{
	t_config	cfg;

	// int			i;

	//Perfom input validation here first before initialisation





	if (init_config(&cfg, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	// i = 0;
	// while (i < cfg.no_phil)
	// {
	// 	printf("Philo: %d | eat times: %d | cfg addr: %p | r_fork: %p | l_fork: %p\n", 
	// 	(&cfg.philos[i])->p_no, (&cfg.philos[i])->eat_times, (&cfg.philos[i])->config, (&cfg.philos[i])->r_fork, (&cfg.philos[i])->l_fork);
	// 	i++;
	// }


	sleep(5);








	join_philos(cfg.cust, cfg.no_phil);
	dishwasher(&cfg);



	return (EXIT_SUCCESS);




}


/*
	to do:
		- validation for the input arguments

*/
