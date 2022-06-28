/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:43:13 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:41:25 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	check_round(t_data *data, int *meal_count)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(data->mutex_for_check);
		if (time_delta(data->philo_data[i].last_eating) > data->time_to_die)
		{
			ft_print(data, i, DEAD);
			pthread_mutex_unlock(data->mutex_for_check);
			return (FALSE);
		}
		pthread_mutex_unlock(data->mutex_for_check);
		if (data->philo_data[i].full_meal == 1)
			(*meal_count)++;
		i++;
	}
	return (TRUE);
}

int	checker(t_data *data)
{
	int	meal_count;

	meal_count = 0;
	while (1)
	{
		meal_count = 0;
		if (check_round(data, &meal_count) == FALSE)
			return (FALSE);
		if (meal_count >= data->number_of_philosophers)
			return (FALSE);
	}
	return (TRUE);
}
