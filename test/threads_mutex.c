#include <pthread.h>
#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#define MAX_ITER 25000

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
	pthread_t		tid1;
	pthread_t		tid2;
	t_counter		count;

	count.ct = 0;

	//Init mutex
	pthread_mutex_init(&count.ct_mutex, NULL);

	//Thread creation
	printf(RED "Main: Creating a first thread now" RESET "\n");
	pthread_create(&tid1, NULL, thread_routine, &count);
	printf(RED "Main: First thread created" RESET "\n");

	printf(RED "Main: Creating a second thread now" RESET "\n");
	pthread_create(&tid2, NULL, thread_routine, &count);
	printf(RED "Main: Second thread created" RESET "\n");

	//Joining threads
	pthread_join(tid1, NULL);
	printf(RED "Main: joined thread: %ld" RESET "\n", tid1);

	pthread_join(tid2, NULL);
	printf(RED "Main: joined thread: %ld" RESET "\n", tid2);


	//Final count, mutex not required since all threads are joined already
	printf(BLUE "Main: Final count after the 2 threads: %d" RESET "\n", count.ct);


	//Destroy mutex
	pthread_mutex_destroy(&count.ct_mutex);

	return (0);
}
