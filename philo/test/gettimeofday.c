#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

int	main(void)
{
	struct timeval	tv;
	int				i;
	long			s_sec;
	long			s_msec;
	long			s_allmsec;
	long			e_sec;
	long			e_msec;
	long			e_allmsec;


	i = 0;
	printf("Max long: %ld\n", LONG_MAX);
	printf("Max int: %ld\n", INT_MAX);


	while (i < 5)
	{
		if (gettimeofday(&tv, NULL) != 0)
		{
			perror("gettimeofday failed");
			exit(EXIT_FAILURE);
		};

		s_allmsec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		printf("Milliseconds from epoch: %ld\n", s_allmsec);
		i++;

		usleep(1500000);
		if (gettimeofday(&tv, NULL) != 0)
		{
			perror("gettimeofday failed");
			exit(EXIT_FAILURE);
		};
		e_allmsec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		printf("Milliseconds from epoch: %ld | sleep time in ms: %ld\n", e_allmsec, e_allmsec - s_allmsec);
	}

	return (EXIT_SUCCESS);
}
