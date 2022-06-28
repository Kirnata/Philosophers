/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_your_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:14:16 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:51:48 by ptopping         ###   ########.fr       */
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
	if (philo_data->data->number_of_times_each_philosopher_must_eat > 0)
	{
		while (philo_data->data->must_die == 0)
		{
			if (time_must_eat == 0)
				philo_data->full_meal = 1;
			execute_life_circle(philo_data);
			time_must_eat--;
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
		usleep(50);
	if (ft_print(philo_data->data, philo_data->philos_id, THINK_MSG))
		return (FALSE);
	usleep(philo_data->data->time_to_eat);
	if (ft_eating(philo_data) == FALSE)
		return (FALSE);
	if (ft_sleep(philo_data) == FALSE)
		return (FALSE);
	return (0);
}

int	ft_eating(t_philo_data *philo_data)
{
	pthread_mutex_lock(philo_data->left_fork);
	if (ft_print(philo_data->data, philo_data->philos_id, TAKE_L_F))
		return (FALSE);
	pthread_mutex_lock(philo_data->right_fork);
	if (ft_print(philo_data->data, philo_data->philos_id, TAKE_R_F))
		return (FALSE);
	if (ft_print(philo_data->data, philo_data->philos_id, EAT_MSG))
		return (FALSE);
	ft_usleep(philo_data->data->time_to_eat, philo_data->last_eating);
	pthread_mutex_unlock(philo_data->right_fork);
	pthread_mutex_unlock(philo_data->left_fork);
	pthread_mutex_lock(philo_data->data->mutex_for_check);
	philo_data->last_eating = get_time();
	pthread_mutex_unlock(philo_data->data->mutex_for_check);
	return (TRUE);
}

int	ft_sleep(t_philo_data *philo_data)
{
	if (ft_print(philo_data->data, philo_data->philos_id, SLEEP_MSG))
		return (FALSE);
	ft_usleep(philo_data->data->time_to_sleep, philo_data->last_eating);
	return (TRUE);
}
