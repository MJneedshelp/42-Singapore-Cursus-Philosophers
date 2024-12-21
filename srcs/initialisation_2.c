/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:12:44 by mintan            #+#    #+#             */
/*   Updated: 2024/12/21 08:38:56 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Performs all the memory allocation required for the programme.
   If any of the malloc fails, free any allocated memory and return
   EXIT_FAILURE.
*/

int	init_memory(t_config *cfg)
{
	cfg->bill = (int *)malloc(cfg->no_phil * sizeof(int));	//rmb to set all to FALSE
	cfg->cust = (pthread_t *)malloc(cfg->no_phil * sizeof(pthread_t));
	cfg->mt_forks = (pthread_mutex_t *)malloc(cfg->no_phil * sizeof(pthread_mutex_t));
	cfg->philos = (t_philo *)malloc(cfg->no_phil * sizeof(t_philo));
	if (cfg->bill == NULL || cfg->cust == NULL || \
	cfg->mt_forks == NULL || cfg->philos == NULL)
	{
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* Description: Creates all the mutex required by the programme. Destroys
   previously created mutex if the current mutex creation fails
*/

int	init_all_mutex(t_config *cfg)
{
	if (mutex_init(&(cfg->mt_cfg)) == EXIT_FAILURE)
	{
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	if (mutex_init(&(cfg->mt_print)) == EXIT_FAILURE)
	{
		destroy_all_mutex(cfg, 1);
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	if (create_forks(cfg->mt_forks, cfg->no_phil) == EXIT_FAILURE)
	{
		destroy_all_mutex(cfg, 2);
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	if (init_philos(cfg, cfg->philos, cfg->no_phil) == EXIT_FAILURE)
	{
		destroy_all_mutex(cfg, 3);
		dishwasher(cfg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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
	if (init_memory(cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all_mutex(cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
