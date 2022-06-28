/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:48:06 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 15:04:15 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		time_normalize;

	gettimeofday(&time, 0);
	time_normalize = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_normalize);
}

long long	time_delta(long long last_time)
{
	long long	new_time;

	new_time = get_time();
	if (new_time == last_time)
		return (0);
	return (new_time - last_time);
}
