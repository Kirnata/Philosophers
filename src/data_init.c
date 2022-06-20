#include "../inc/philo.h"
#include "../inc/messages.h"

int	data_init(t_data *data, int argc, char *argv[])
{ 
	if (argc == 5 || argc == 6)
	{
		data->number_of_philosophers = ft_philo_atoi(argv[1]);
		data->time_to_die = ft_philo_atoi(argv[2]);
		data->time_to_eat = ft_philo_atoi(argv[3]);
		data->time_to_sleep = ft_philo_atoi(argv[4]);
		if (argc == 5)
			data->number_of_times_each_philosopher_must_eat = -1;
		else if (argc == 6)
			data->number_of_times_each_philosopher_must_eat = ft_philo_atoi(argv[5]);
	}
	else
	{
		printf(ERROR_ARGS_NUM);
		return (1);
	}
	return (0);
}