/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:40:34 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 00:29:36 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"
//разобраться с destroy(после того как все потоки заджойнили)

int	ft_mutex_unlock(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_unlock(&data->mtxs[i]);
		i++;
	}
	pthread_mutex_unlock(data->mutex_for_print);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	if (data_init(&data, argc, argv) == FALSE)
		return (FALSE);
	if (mutex_create(&data) == FALSE)
		return (FALSE);
	if (create_philo(&data) == FALSE)
		return (FALSE);
	if (create_philo_threads(&data) == FALSE)
		return (FALSE);
	//exit(0);
	printf("after philo treads\n");
	printf("%d - must_die\n", data.must_die);
	//sleep(10);
	if (join_threads(&data) == FALSE)
		return (FALSE);
	printf("after join_threads\n");
	if (ft_mutex_unlock(&data) == FALSE)
		return (FALSE);
	printf("ft_mutex_unlock\n");
	if (ft_mutex_destroy(&data) == FALSE)
		return (FALSE);
	printf("ft_mutex_destroy\n");
	philo_free(&data);
	printf("after philo_free\n");
	return (0);
}

int	(ft_mutex_destroy(t_data *data))
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&data->mtxs[i]))
			return (FALSE);
		i++;
	}
	if (pthread_mutex_destroy(data->mutex_for_print))
		return (FALSE);
	return (TRUE);
}

void	philo_free(t_data *data)
{
	free(data->philo_data);
	free(data->mutex_for_print);
}