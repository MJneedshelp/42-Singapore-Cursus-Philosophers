#include <pthread.h>
#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#define MAX_ITER 1000000
#define NO_THREADS 8

typedef struct s_counter
{
	pthread_mutex_t	ct_mutex;
	unsigned int	ct;

}	t_counter;



void	*thread_routine(void *data)
{
	pthread_t		tid;
	t_counter		*count;
	int				i;

	i = 0;
	tid = pthread_self();
	count = (t_counter *)data;

	pthread_mutex_lock(&count->ct_mutex);
	printf(GREEN "Thread: %ld | Count at start: %d" RESET "\n", tid, count->ct);
	pthread_mutex_unlock(&count->ct_mutex);

	while (i < MAX_ITER)
	{
		pthread_mutex_lock(&count->ct_mutex);
		count->ct++;
		pthread_mutex_unlock(&count->ct_mutex);
		i++;
	}

	pthread_mutex_lock(&count->ct_mutex);
	printf(GREEN "Thread: %ld | Count at end: %d" RESET "\n", tid, count->ct);
	pthread_mutex_unlock(&count->ct_mutex);
	return (NULL);
}




int	main(void)
{
	pthread_t		thr[NO_THREADS];
	t_counter		count;
	int				i;

	count.ct = 0;


	//Init mutex
	pthread_mutex_init(&count.ct_mutex, NULL);

	//Thread creation
	i = 0;
	while (i < NO_THREADS)
	{
		pthread_create(&(thr[i]), NULL, thread_routine, &count);
		i++;
	}

	//Joining threads
	i = 0;
	while (i < NO_THREADS)
	{
		pthread_join(thr[i], NULL);
		i++;
	}


	//Final count, mutex not required since all threads are joined already
	printf(BLUE "Main: Final count after the %d threads: %d" RESET "\n", NO_THREADS, count.ct);


	//Destroy mutex
	// pthread_mutex_destroy(&count.ct_mutex);

	return (0);
}
