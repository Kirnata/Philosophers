#include "../inc/philo.h"
#include "../inc/messages.h"

void *all_your_life(void *args)
{
	t_philo_data *philo_data;
	int time_must_eat;

	philo_data = (t_philo_data *)args;
	time_must_eat = philo_data->data->number_of_times_each_philosopher_must_eat;
	// usleep(100);
	while (philo_data->data->must_die == 0)
	{
		if (time_must_eat == 0)
			philo_data->full_meal = 1;
		else if (time_must_eat > 0)
			time_must_eat--;
		execute_life_circle(philo_data);
	}
	return (0);
}

int	execute_life_circle(t_philo_data *philo_data)
{
	if (philo_data->philos_id % 2 == 0)
		usleep(100);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, THINK_MSG);
	//usleep();по значению инпута что  нибудь придумать
	pthread_mutex_lock(philo_data->left_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, TAKE_L_F);
	pthread_mutex_lock(philo_data->right_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, TAKE_R_F);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, EAT_MSG);
	philo_data->last_eating = get_time();
	ft_usleep(philo_data->data->time_to_eat, philo_data->last_eating);
	pthread_mutex_unlock(philo_data->right_fork);
	pthread_mutex_unlock(philo_data->left_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, SLEEP_MSG);
	ft_usleep(philo_data->data->time_to_sleep, philo_data->last_eating);
	//поставить какое нибудь условие на смену must_to _die
	return (0);
}


