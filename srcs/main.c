/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:25:48 by mintan            #+#    #+#             */
/*   Updated: 2024/12/07 12:36:13 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"




void	init_philo(t_philo *philo, int argc, char *argv[])
{
	philo->no_phil = ft_atoi(argv[1]);
	philo->die_ms = ft_atoi(argv[2]);
	philo->eat_ms = ft_atoi(argv[3]);
	philo->sleep_ms = ft_atoi(argv[4]);
	philo->eat_reps = -1;
	if (argc > 5)
		philo->eat_reps = ft_atoi(argv[5]);
	philo->cust = (pthread_t *)malloc(philo->no_phil * sizeof(pthread_t));
	arise_philos(philo);
}






int	main(int argc, char *argv[])
{
	t_philo	philo;

	init_philo(&philo, argc, argv);

	sleep(5);
	printf("philo number: %d | die time: %d | eat time: %d | sleep time: %d | eat reps: %d\n", philo.no_phil, philo.die_ms, philo.eat_ms, philo.sleep_ms, philo.eat_ms);
	printf("philo address: %p\n", philo.cust);




	return (EXIT_SUCCESS);




}


/*
	to do:
		- validation for the input arguments

*/
