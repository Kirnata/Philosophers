/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_your_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:14:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/27 18:50:36 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

void	*all_your_life(void *args)
{
	t_philo_data	*philo_data;
	int				time_must_eat;

	philo_data = (t_philo_data *)args;
	time_must_eat = philo_data->data->number_of_times_each_philosopher_must_eat;
	printf("%d - time_must_eat\n", time_must_eat);
	// while (philo_data->data->must_die == 0)
	// {
	// 	if (time_must_eat > 0)
	// 		time_must_eat--;
	// 	else if (time_must_eat == 0)
	// 		philo_data->full_meal = 1;
	// 	printf("%d - time_must_eat in circle in %d tread\n", time_must_eat, philo_data->philos_id);
	// 	printf("%d - full_meal in circle in %d tread\n", philo_data->full_meal, philo_data->philos_id);
	// 	// sleep(1500);
	// 	execute_life_circle(philo_data);
	// }
	if (philo_data->data->number_of_times_each_philosopher_must_eat > 0)
	{
		while (philo_data->data->must_die == 0)
		{
			execute_life_circle(philo_data);
			if (time_must_eat == 0)
				philo_data->full_meal = 1;
			time_must_eat--;
		}
	}
	if (philo_data->data->number_of_times_each_philosopher_must_eat > 0)
	{
		while (philo_data->data->must_die == 0)
			execute_life_circle(philo_data);
	}
	return (0);
}
//НЕ ВЫХОДИТ ИЗ ЦИКЛА ПО КОЛИЧЕСТВУ ЕДЫ!!!!!!!!!!!!!

int	execute_life_circle(t_philo_data *philo_data)
{
	if (philo_data->philos_id % 2 == 0)
		usleep(1000);
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


