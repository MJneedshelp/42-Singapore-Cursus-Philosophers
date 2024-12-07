#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	tv;
	int				i;

	i = 0;
	while (i < 5)
	{
		if (gettimeofday(&tv, NULL) != 0)
		{
			perror("gettimeofday failed");
			exit(EXIT_FAILURE);
		}
		printf("Seconds from epoch: %ld\n", tv.tv_sec);
		printf("Microseconds past the current second:%ld\n", tv.tv_usec);
		i++;
		sleep(1);
	}

	return (EXIT_SUCCESS);
}
