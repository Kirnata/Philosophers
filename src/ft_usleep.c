#include "../inc/philo.h"
#include "../inc/messages.h"

void ft_usleep(size_t ms_to_sleep, long long last_time)
{
	long long new_time;

	new_time = get_time();
	usleep(last_time + ms_to_sleep - new_time);
}