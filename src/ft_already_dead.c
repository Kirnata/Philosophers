#include "../inc/philo.h"
#include "../inc/messages.h"

int ft_already_dead(t_philo_data *philo_data)
{
	int	delta;
	delta = time_delta(philo_data->last_eating);
	if (delta > philo_data->data->time_to_die)
		return (FALSE);
	return (TRUE);
}