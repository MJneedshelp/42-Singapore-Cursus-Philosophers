#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

typedef struct s_food
{
	pthread_mutex_t	mt_food;
	pthread_cond_t	con_food;
	unsigned int	food;

}	t_food;

void	*food_eat(void *data)
{
	pthread_t		tid;
	t_food			*food;


	tid = pthread_self();
	food = (t_food *)data;
	printf("Thread: %ld | Eat food\n", tid);

	pthread_mutex_lock(&(food->mt_food));
	while (food->food < 35)
	{
		printf("Waiting for food...\n");
		pthread_cond_wait(&food->con_food, &food->mt_food);		//unlocks mutex -> wait for signal -> lock mutex
	}

	food->food -= 35;
	printf("food left: %d\n", food->food);
	pthread_mutex_unlock(&(food->mt_food));


	return (NULL);
}

void	*food_fill(void *data)
{
	pthread_t		tid;
	int				i;
	t_food			*food;

	tid = pthread_self();
	i = 0;
	food = (t_food *)data;
	printf("Thread: %ld | Fill food\n", tid);
	while (i < 5)
	{
		pthread_mutex_lock(&(food->mt_food));
		food->food += 10;
		printf("food: %d\n", food->food);
		pthread_mutex_unlock(&(food->mt_food));
		pthread_cond_signal(&food->con_food);
		sleep(1);
		i++;
	}

	return (NULL);
}



int	main(void)
{
	pthread_t		thr[2];
	int				i;
	t_food			food;

	food.food = 0;

	//Init mutex and condition
	pthread_mutex_init(&food.mt_food, NULL);
	pthread_cond_init(&food.con_food, NULL);


	//Thread creation
	i = 0;
	while (i < 2)
	{
		if (i == 0)
		{
			if (pthread_create(&(thr[i]), NULL, food_fill, &food) != 0)
			{
				perror("Thread: Food fill failed\n");
				exit (EXIT_FAILURE);
			}
		}
		else
		{
			if (pthread_create(&(thr[i]), NULL, food_eat, &food) != 0)
			{
				perror("Thread: Food eat failed\n");
				exit (EXIT_FAILURE);
			}
		}
		i++;
	}

	//Joining threads
	i = 0;
	while (i < 2)
	{
		pthread_join(thr[i], NULL);
		i++;
	}




	//Destroy mutex
	pthread_mutex_destroy(&food.mt_food);
	pthread_cond_destroy(&food.con_food);

	return (0);
}
