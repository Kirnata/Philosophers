/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:32:07 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 00:13:48 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	printf("in join_threads\n");
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philo_data[i].philos_thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	printf("in join_threads 2\n");
	return (TRUE);
}
