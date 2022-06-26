#include "../inc/philo.h"
#include "../inc/messages.h"

long long	get_time()
{
	struct timeval time;
	long long time_normalize;
	gettimeofday(&time, 0);
	time_normalize = time.tv_sec * 1000 + time.tv_usec / 1000;
	//printf("%lld\n", time_normalize);
	return (time_normalize);
}

long long	time_delta(long long last_time)
{
	long long new_time;
	new_time = get_time();
	// printf("%lld - new_time\n", new_time);
	// printf("%lld - last_time\n", last_time);
	// printf("%int - time_delta\n", time_delta);
	if (new_time == last_time)
		return (0);
	return (new_time - last_time);
}