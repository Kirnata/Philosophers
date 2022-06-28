/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:47:42 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 18:26:11 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/messages.h"

void	ft_usleep(size_t ms_to_sleep, long long last_time)
{
	usleep(ms_to_sleep - 50);
	if (get_time() - last_time < ms_to_sleep)
	{
		while (get_time() - last_time < ms_to_sleep)
			usleep(10);
	}
}
