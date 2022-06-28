/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_treads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:26:07 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:44:14 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

void	time_init(t_data *data)
{
	int			i;
	long long	last_time;

	i = 0;
	last_time = get_time();
	while (i < data->number_of_philosophers)
	{
		data->philo_data[i].last_eating = last_time;
		i++;
	}
}

int	create_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	time_init(data);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philo_data[i].philos_thread, \
		NULL, &all_your_life, &data->philo_data[i]))
		{
			printf(ERROR_CREATE_THREAD);
			return (FALSE);
		}
		i++;
	}
	if (checker(data))
		data->must_die = 1;
	return (TRUE);
}
