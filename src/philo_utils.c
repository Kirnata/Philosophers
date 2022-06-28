/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:04 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:41:48 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_philo_atoi(const char *str)
{	
	long	i;
	long	number;

	i = 0;
	number = 0;
	if (str[i] != '\0' && str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (number > INT_MAX || (!ft_isdigit(str[i]) && str[i] != '\0'))
		return (0);
	return ((int)(number));
}

int	ft_print(t_data *data, int i, char *str)
{
	if (data->must_die == 0)
	{
		pthread_mutex_lock(data->mutex_for_print);
		printf("%d %s", i, str);
		pthread_mutex_unlock(data->mutex_for_print);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
