#include "../inc/philo.h"
#include "../inc/messages.h"

long long	get_time()
{
	struct timeval time;
	long long time_normalize;
	gettimeofday(&time, 0);
	time_normalize = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_normalize);
}

int	time_delta(int last_time)
{
	long long new_time;
	int time_delta;
	new_time = get_time();
	time_delta = new_time - last_time;
	return (time_delta);
}