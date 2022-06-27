/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:51:15 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/27 17:01:04 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	mutex_create(t_data *data)
{
	int	i;

	i = 0;
	data->mtxs = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->mtxs)
		return (FALSE);
	data->mutex_for_print = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_for_print)
		return (FALSE);
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
	return (TRUE);
}
