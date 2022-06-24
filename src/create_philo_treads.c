#include "../inc/philo.h"
#include "../inc/messages.h"

int	create_philo_threads(t_data *data)
{
	int i;

	i = 0;
	printf("hui in create_philo_threads\n");
	//exit(0);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philo_data[i].philos_thread, NULL, &all_your_life, &data->philo_data[i]) != 0)
		{
			printf(ERROR_CREATE_THREAD);
			return (1);
		}
		i++;
	}
	if (join_threads(data) == FALSE)
		return (FALSE);
	exit(0);
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
