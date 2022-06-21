#include "../inc/philo.h"
#include "../inc/messages.h"

int	create_philo_threads(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("hui in create_philo_threads\n");
	//exit(0);
	while (i < data->number_of_philosophers)
	{
		j = pthread_create(&data->philo_data[i].philos_thread, NULL, &all_your_life, &data);
		if (j != 0)
		{
			printf(ERROR_CREATE_THREAD);
			return (1);
		}
		i++;
	}
	return (0);
}
