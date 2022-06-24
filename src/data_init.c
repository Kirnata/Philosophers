#include "../inc/philo.h"
#include "../inc/messages.h"

int	data_init(t_data *data, int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "HELP") == TRUE)
	{
		printf(HELP_MSG);
		return (FALSE);
	}
	else if (argc == 5 || argc == 6)
	{
		data->number_of_philosophers = ft_philo_atoi(argv[1]);
		data->time_to_die = ft_philo_atoi(argv[2]);
		data->time_to_eat = ft_philo_atoi(argv[3]);
		data->time_to_sleep = ft_philo_atoi(argv[4]);
		if (argc == 5)
			data->number_of_times_each_philosopher_must_eat = -1;
		else if (argc == 6)
			data->number_of_times_each_philosopher_must_eat = ft_philo_atoi(argv[5]);
		if (!data->number_of_philosophers || !data->time_to_die || !data->time_to_eat ||
			!data->time_to_sleep || !data->number_of_times_each_philosopher_must_eat)
		{
			printf(ERROR_VALID_ARGS);
			printf(FOR_HELP);
			return (FALSE);
		}
		data->must_die = 0;
	}
	else
	{
		printf(ERROR_ARGS_NUM);
		return (FALSE);
	}
	// printf("%d->number_of_philosophers\n", data->number_of_philosophers);
	// printf("%d->time_to_die\n", data->time_to_die);
	// printf("%d->time_to_eat\n", data->time_to_eat);
	// printf("%d->time_to_sleep\n", data->time_to_sleep);
	// printf("%d->number_of_times_each_philosopher_must_eat\n", data->number_of_times_each_philosopher_must_eat);
	// exit(0);
	return (0);
}
