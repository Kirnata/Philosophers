/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:51:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 19:04:22 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->mtxs[i++], NULL))
		{
			printf(ERROR_MX_INIT);
			return (FALSE);
		}
	}
	if (pthread_mutex_init(data->mutex_for_print, NULL))
	{
		printf(ERROR_MX_INIT);
		return (FALSE);
	}
	if (pthread_mutex_init(data->mutex_for_check, NULL))
	{
		printf(ERROR_MX_INIT);
		return (FALSE);
	}
	return (TRUE);
}

int	mutex_create(t_data *data)
{
	data->mtxs = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->mtxs)
		return (FALSE);
	data->mutex_for_print = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_for_print)
		return (FALSE);
	data->mutex_for_check = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_for_check)
		return (FALSE);
	if (ft_mutex_init(data) == FALSE)
		return (FALSE);
	return (TRUE);
}
