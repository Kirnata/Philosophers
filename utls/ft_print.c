#include "../inc/philo.h"
#include "../inc/messages.h"

int	ft_print(pthread_mutex_t *mutex_for_print, int i, char *str)
{
	pthread_mutex_lock(mutex_for_print);
	printf("%d %s", i, str);
	pthread_mutex_unlock(mutex_for_print);
	return (0);
}