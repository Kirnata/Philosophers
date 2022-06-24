#include "../inc/philo.h"
#include "../inc/messages.h"

void *all_your_life(void *args)
{
	t_philo_data *philo_data;
	int i;

	philo_data = (t_philo_data *)args;
	i = 0;
	philo_data->last_eating = get_time();
	if (philo_data->data->number_of_times_each_philosopher_must_eat > 0)//это минимальное количество пожрать, то есть нужно чтобы все поели и выйти
	{
		while (i < philo_data->data->number_of_times_each_philosopher_must_eat && !ft_already_dead(philo_data))
		{
			printf("huihuihui in all_your_life\n");
			execute_life_circle(philo_data);
			i++;
		}
	}
	else
	{
		while (philo_data->data->must_die == 0)
			execute_life_circle(philo_data);
	}
	return (0);
}

int	execute_life_circle(t_philo_data *philo_data)
{
	if (philo_data->philos_id % 2 == 0)
		usleep(2500);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, THINK_MSG);
	//usleep();по значению инпута что  нибудь придумать
	pthread_mutex_lock(philo_data->left_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, TAKE_L_F);
	pthread_mutex_lock(philo_data->right_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, TAKE_R_F);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, EAT_MSG);
	philo_data->last_eating = get_time();
	usleep(philo_data->data->time_to_eat);
	pthread_mutex_unlock(philo_data->right_fork);
	pthread_mutex_unlock(philo_data->left_fork);
	ft_print(philo_data->data->mutex_for_print, philo_data->philos_id, SLEEP_MSG);
	usleep(philo_data->data->time_to_sleep);
	//поставить какое нибудь условие на смену must_to _die
	return (0);
}


