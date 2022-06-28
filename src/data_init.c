/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:43:48 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 19:13:04 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	data_init(t_data *data, int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "HELP") == TRUE)
	{
		printf(HELP_MSG);
		return (FALSE);
	}
	else if (argc == 5 || argc == 6)
	{
		fill_data(data, argc, argv);
		if (ft_errors_in_init(data))
			return (FALSE);
		data->must_die = 0;
	}
	else
	{
		printf(ERROR_ARGS_NUM);
		return (FALSE);
	}
	return (TRUE);
}

int	fill_data(t_data *data, int argc, char *argv[])
{
	data->number_of_philosophers = ft_philo_atoi(argv[1]);
	data->time_to_die = ft_philo_atoi(argv[2]);
	data->time_to_eat = ft_philo_atoi(argv[3]);
	data->time_to_sleep = ft_philo_atoi(argv[4]);
	if (argc == 5)
		data->number_of_times_each_philosopher_must_eat = -1;
	else if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = \
		ft_philo_atoi(argv[5]);
	return (0);
}

int	ft_errors_in_init(t_data *data)
{
	if (!data->number_of_philosophers || !data->time_to_die || \
	!data->time_to_eat || !data->time_to_sleep || \
	!data->number_of_times_each_philosopher_must_eat)
	{
		printf(ERROR_VALID_ARGS);
		printf(FOR_HELP);
		return (FALSE);
	}
	return (TRUE);
}
