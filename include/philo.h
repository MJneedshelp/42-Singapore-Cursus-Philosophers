/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:49:46 by mintan            #+#    #+#             */
/*   Updated: 2024/12/23 20:43:42 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

/* Colours used for formatting printf*/
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;93m"
# define PURPLE "\033[0;95m"
# define NORM_WHITE "\033[0;37m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

/* Define the max number of philos accepted */
# define MAX_PHILOS 100

/* Define the min time to die */
# define MIN_DIE_MS 200

/* Define the delay at the start before the waiter to check */
# define WAITER_WAIT 10000

/* Error messages */
# define ERR_NO_ARG_1 "Please run the programme with only the following args: "
# define ERR_NO_ARG_2 "No. of philos, time to die, time to eat, time to sleep, "
# define ERR_NO_ARG_3 "and the number of times each philo eats (optional)."
# define ERR_ARG_NUMERIC_1 "Please ensure that all your args are positive ints"
# define ERR_DIE_FAST_1 "This is not a speed eating competition! > 200ms !"
# define ERR_EAT_AIR_1 "Get out of here if you're not hungry!"


# define ERR_TABLE_LIMIT_1 "This table only seats between 1 and "
# define ERR_TABLE_LIMIT_2 " customers"
# define ERR_EG_1 "E.g. ./philo 10 410 200 200 10"
# define ERR_EG_2 "E.g. ./philo 10 410 200 200"

/* Forward declare s_config and s_philo as they will be referencing
   each other */

typedef struct s_config	t_config;
typedef struct s_philo	t_philo;

/* Enumerables for easier reading */
enum	e_bool
{
	FALSE = 24,
	TRUE = 42
};

enum	e_err_type
{
	ERR_NO_ARGS,
	ERR_ARG_NUMERIC,
	ERR_DIE_FAST,
	ERR_EAT_AIR,
	ERR_TABLE_LIMIT
};

enum	e_state
{
	EATING,
	THINKING,
	SLEEPING,
	GRAB_FIRST_FORK,
	GRAB_SECOND_FORK,
	DEAD,
	START
};

/* Define s_config struct. Configuration structure to hold all the important
   information
*/
typedef struct s_config
{
	int				no_phil;
	int				*bill;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				think_ms;
	int				eat_reps;
	int				meal_end;
	int				all_seated;
	pthread_t		*cust;
	pthread_mutex_t	mt_cfg;
	pthread_mutex_t	mt_print;
	pthread_mutex_t	*mt_forks;
	t_philo			*philos;
}	t_config;

/* Define the s_philo struct. Contains the characteristics of each philo thread
*/
typedef struct s_philo
{
	int				p_no;
	int				full;
	long			eat_times;
	long			ms_last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	mt_me;
	t_config		*cfg;
}	t_philo;

/* Initialisation */
int		input_validation(int argc, char *argv[]);
int		init_philos(t_config *cfg, t_philo *philos, int no_phil);
int		arise_philos(t_config *cfg);
int		create_forks(pthread_mutex_t *mt_forks, int no_phil);
int		init_config(t_config *cfg, int argc, char *argv[]);

/* Meal time */
void	*meal_start(void *data);

/* Waiter functions */
void	*waiter_start(void *data);

/* Clean-up functions */
void	join_philos(pthread_t *cust, int num);
void	destroy_forks_mutex(pthread_mutex_t *mt_arr, int n);
void	destroy_philo_mutex(t_philo *philos, int n);
void	destroy_all_mutex(t_config *cfg, int levels);
void	dishwasher(t_config *config);

/* Utility functions */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int a);
long	checktime(void);
long	print_status(int p_no, int status, t_philo *me);

/* Mutex utility functions */
int		mutex_init(pthread_mutex_t *mt);
void	set_bool(int *bool, int bool_val, pthread_mutex_t *mt);
int		get_bool(int *bool, pthread_mutex_t *mt);
void	set_long(long *l_nbr, long long_val, pthread_mutex_t *mt);
long	get_long(long *l_nbr, pthread_mutex_t *mt);

#endif
