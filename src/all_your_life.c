#include "../inc/philo.h"
#include "../inc/messages.h"

void *all_your_life(void *args)
{
	t_data *data;
	int i;

	data = (t_data *)args;
	i = data->current_thread_num;
	printf("I was born\n");
	printf("who is there? %d thread\n", i);
	while (1)
	{
		if (data->philo_data[i].philos_num % 2 == 0)
			usleep(2500);
		printf("who is there?\n");
		printf("%d is thinking\n", data->philo_data[i].philos_num);
		pthread_mutex_lock(data->philo_data[i].left_fork);
		printf("%d has taken a left fork\n", data->philo_data[i].philos_num);
		pthread_mutex_lock(data->philo_data[i].right_fork);
		printf("%d has taken a right fork\n", data->philo_data[i].philos_num);
		printf("%d is eating\n", data->philo_data[i].philos_num);
		//gettimeofday(data->philo_data->last_eating);
		usleep(data->time_to_eat);
		pthread_mutex_unlock(data->philo_data[i].right_fork);
		pthread_mutex_unlock(data->philo_data[i].left_fork);
		printf("%d is sleeping\n", data->philo_data[i].philos_num);
		usleep(data->time_to_sleep);
	}
	return (0);
}
