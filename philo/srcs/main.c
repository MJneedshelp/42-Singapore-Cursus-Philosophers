/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/24 05:11:15 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Description: Main function of the programme. Sequence of events:
	1. Input validation: Exit programme if there are input errors / edge cases
	2. Initialise configuration: Exit programme if there are memory allocation
	   / pthread_mutex_create errors
	3. Create philo threads: Exit programme if there are pthread_create errors
	4. Signal that all philos are seated at the table
	5. Create waiter thread
	6. Join the all the created threads, philos and waiter
	7. Destory all creted mutex
	8. Free all allocated memory
*/

int	main(int argc, char *argv[])
{
	t_config	cfg;
	pthread_t	waiter;

	if (input_validation_1(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (input_validation_2(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_config(&cfg, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (arise_philos(&cfg) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	set_long(&(cfg.start_time), checktime(), &cfg.mt_print);
	set_bool(&(cfg.all_seated), TRUE, &cfg.mt_cfg);

	// cfg.start_time = checktime();
	if (pthread_create(&waiter, NULL, waiter_start, &cfg) != 0)
	{
		destroy_all_mutex(&cfg, 4);
		dishwasher(&cfg);
		return (EXIT_FAILURE);
	}
	pthread_join(waiter, NULL);
	join_philos(cfg.cust, cfg.no_phil);
	destroy_all_mutex(&cfg, 4);
	dishwasher(&cfg);
	return (EXIT_SUCCESS);
}
