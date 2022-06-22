#include "../inc/philo.h"
#include "../inc/messages.h"

int	mutex_create(t_data *data)
{
	int i;

	i = 0;
	data->mtxs = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->mtxs)
	{
		printf(ERROR_MALLOC);
		return (FALSE);
	}
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->mtxs[i], NULL) != 0)
		{
			printf(ERROR_MX_INIT);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
