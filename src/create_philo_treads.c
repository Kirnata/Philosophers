#include "../inc/philo.h"
#include "../inc/messages.h"

void	time_init(t_data *data)
{
	long long last_time;
	int i;

	last_time = get_time();
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philo_data[i].last_eating = last_time;
		i++;
	}
}

int	create_philo_threads(t_data *data)
{
	int i;

	i = 0;
	printf("hui in create_philo_threads\n");
	time_init(data);

	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philo_data[i].philos_thread, NULL, &all_your_life, &data->philo_data[i]) != 0)
		{
			printf(ERROR_CREATE_THREAD);
			return (1);
		}
		i++;
	}
	// usleep(10000);
	if (checker(data) == FALSE)
		data->must_die = 1;
	return (0);
}



int join_threads(t_data *data)
{
	int i;
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philo_data[i].philos_thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
