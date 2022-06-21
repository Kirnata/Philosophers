#include "../inc/philo.h"
#include "../inc/messages.h"

int	create_philo(t_data *data)
{
	int i;
	int j;
	int status;

	i = 0;
	j = 1;
	status = 0;
	data->philo_data = malloc(sizeof(t_philo_data) * (data->number_of_philosophers + 1));
	while (j < data->number_of_philosophers)
	{
		fill_philo_data(data, i, j);
		// status = pthread_create(data->philo_data[i]->philos_thread, NULL, philo_routine, NULL);
		// if (status != 0)
		// {
		// 	printf(ERROR_CREATE_THREAD);
		// 	return (1);
		// }уже запускает функцию жизни, поэтому уже послесоздания мьютексов
		i++;
		j++;
	}
	j = 0;
	fill_philo_data(data, i, j);
}

fill_philo_data(t_data *data, int i, int j)
{
	data->philo_data[i].philos_num = i + 1;
	data->philo_data[i].left_fork = j;
	data->philo_data[i].right_fork = j + 1;
	data->philo_data[i].must_die = 0;
	data->philo_data[i].last_eating = 0;
	//может еще что-нибудь
}