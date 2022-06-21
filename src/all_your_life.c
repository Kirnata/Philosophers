#include "../inc/philo.h"
#include "../inc/messages.h"

void *all_your_life(void *args)
{
	t_data *data;
	data = (t_data *)args;
	printf("I was born\n");
	return (0);
}

// void *all_your_life(void *args)
// {
// 	t_data *data;
// 	data = (t_data *)args;
// 	printf("pumpumpum\n");
// 	while (1)
// 	{
//		if (номер философа % 2 == 0)
//			usleep(2500);
// 		printf("thinkihg");
// 		lock(left);
// 		printf("left vilka");
// 		lock(right);
// 		printf("right vilka");
// 		printf("philo eating");
//		gettimeofday(last_eating)
// 		usleep(time_to_eat);
// 		unlock(right;
// 		unlock(left);
// 		print("sleeping");
// 		usleep(time_to_sleep);
// 	}
// }