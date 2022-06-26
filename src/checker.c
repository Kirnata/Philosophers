#include "../inc/philo.h"
#include "../inc/messages.h"



int checker(t_data *data)
{
	// printf("checker\n");
	int i;
	int meal_flag;

	i = 0;
	meal_flag = 1;
	while (1)
	{
		while (i < data->number_of_philosophers)
		{
			// printf("%lld - last_eating\n", data->philo_data[i].last_eating);
			// printf("%d - time_to_die\n", data->time_to_die);
			// printf("%lld - time_delta\n", time_delta(data->philo_data[i].last_eating));
			if (time_delta(data->philo_data[i].last_eating) > data->time_to_die)
			{
				ft_print(data->mutex_for_print, i, DEAD);
				return (FALSE);
			}
			if (data->philo_data[i].full_meal == 0)
				meal_flag = 0;
			i++;
		}
		if (meal_flag == 1)
			return (FALSE);
		i = 0;
	}
	return (TRUE);
}