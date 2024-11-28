#include <pthread.h>
#include <stdio.h>
#define MAX_ITER 21000



void	*thread_routine(void *data)
{
	pthread_t		tid;
	unsigned int	*count;
	int				i;

	i = 0;
	tid = pthread_self();
	count = (unsigned int *)data;
	printf("Thread: %ld | Count at start: %d\n", tid, *count);
	while (i < MAX_ITER)
	{
		(*count)++;
		i++;
	}
	printf("Thread: %ld | Count at end: %d\n", tid, *count);
	return (NULL);
}






int	main(void)
{
	pthread_t		tid1;
	pthread_t		tid2;
	unsigned int	count;

	count = 0;

	printf("Main: Creating a first thread now\n");
	pthread_create(&tid1, NULL, thread_routine, &count);
	printf("Main: First thread created\n");

	printf("Main: Creating a second thread now\n");
	pthread_create(&tid2, NULL, thread_routine, &count);
	printf("Main: Second thread created\n");

	pthread_join(tid1, NULL);
	printf("Main: joined thread: %ld\n", tid1);

	pthread_join(tid2, NULL);
	printf("Main: joined thread: %ld\n", tid2);

	printf("Main: Final count after the 2 threads: %d\n", count);
	return (0);
}
