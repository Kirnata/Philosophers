#include "../inc/philo.h"
#include "../inc/messages.h"

void *all_your_life(void *args)
{
	t_data *data;
	int i;

	data = (t_data *)args;
	i = 0;
	printf("%d - i in all_your_life\n", data->current_thread_num);
	exit(0);
	if (data->number_of_times_each_philosopher_must_eat > 0 && data->philo_data->must_die != 1)
	{
		while (i < data->number_of_times_each_philosopher_must_eat)
		{
			execute_life_circle(data, data->current_thread_num);
			i++;
		}
	}
	else
	{
		while (data->philo_data->must_die != 1)
			execute_life_circle(data, data->current_thread_num);
	}
	return (0);
}

int	execute_life_circle(t_data *data, int i)
{
	// if (data->philo_data[i].philos_num % 2 == 0)
	// 	usleep(2500);
	// printf("who is there?\n");
	// printf("%d is thinking\n", data->philo_data[i].philos_id);
	// pthread_mutex_lock(data->philo_data[i].left_fork);
	// printf("%d has taken a left fork\n", data->philo_data[i].philos_id);
	// pthread_mutex_lock(data->philo_data[i].right_fork);
	// printf("%d has taken a right fork\n", data->philo_data[i].philos_id);
	// printf("%d is eating\n", data->philo_data[i].philos_id);
	// //gettimeofday(data->philo_data->last_eating);
	// usleep(data->time_to_eat);
	// pthread_mutex_unlock(data->philo_data[i].right_fork);
	// pthread_mutex_unlock(data->philo_data[i].left_fork);
	// printf("%d is sleeping\n", data->philo_data[i].philos_id);
	// usleep(data->time_to_sleep);
	printf("we are in execute_life_circle, i = %d = %d\n", i, data->current_thread_num);
	return (0);
}
