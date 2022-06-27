/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:24:11 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/27 17:25:00 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	create_philo(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data->philo_data = \
	malloc(sizeof(t_philo_data) * (data->number_of_philosophers + 1));
	if (!data->philo_data)
		return (FALSE);
	while (j < data->number_of_philosophers)
	{
		fill_philo_data(data, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_data(data, i, j);
	return (0);
}

void	fill_philo_data(t_data *data, int i, int j)
{
	data->philo_data[i].philos_thread = 0;
	data->philo_data[i].philos_id = i;
	data->philo_data[i].last_eating = get_time();
	data->philo_data[i].right_fork = &data->mtxs[j];
	data->philo_data[i].left_fork = &data->mtxs[i];
	data->philo_data[i].data = data;
	data->philo_data[i].full_meal = 0;
}
