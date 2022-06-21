#include "../inc/philo.h"
#include "../inc/messages.h"

void *ft_already_dead(void *args)
{
	t_data *data;
	data = (t_data *)args;
	int i;

	i = 1;
	while (i <= data->number_of_philosophers)
	{
		if (data->philo_data[i].must_die == 1)
			return (1);
	}
	return (0);
}