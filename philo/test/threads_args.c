#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"
#define NO_THREADS 8

int	primes[NO_THREADS] = {2, 3, 5, 7, 11, 13, 17, 23};


void	*thread_routine(void *data)
{
	pthread_t	tid;
	int			*addr;

	tid = pthread_self();
	sleep(2);

	addr = (int *)data;
	printf(GREEN "Thread: %ld | Address: %p | Prime: %d" RESET "\n", tid, addr, *addr);
	return (NULL);
}




int	main(void)
{
	pthread_t		thr[NO_THREADS];
	int				i;
	int				*address;

	//Thread creation
	i = 0;
	while (i < NO_THREADS)
	{

		address = &(primes[i]);
		printf("Address in array: %p | value: %d\n", address, *address);
		if (pthread_create(&(thr[i]), NULL, thread_routine, &(primes[i])) != 0)
		{
			perror("Thread creation failed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}

	//Joining threads
	i = 0;
	while (i < NO_THREADS)
	{
		if (pthread_join(thr[i], NULL) != 0)
		{
			perror("Thread join failed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}

	return (0);
}
