#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*routine(void *data)
{
	int	*result;

	result = malloc(sizeof(int));
	*result = 42;
	return (result);
}

int	main(void)
{
	pthread_t	tid;
	int			*result;

	if (pthread_create(&tid, NULL, routine, NULL) != 0)
	{
		perror("Thread creation failed\n");
		return (EXIT_FAILURE);
	}

	if (pthread_join(tid, (void **)&result) !=0)
	{
		perror("Thread join failed\n");
		return (EXIT_FAILURE);
	}

	printf("Thread join result: %d\n", *result);
	return (EXIT_SUCCESS);
}
