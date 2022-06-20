#include "../inc/philo.h"
#include "../inc/messages.h"
//разобраться с destroy(после того как все потоки заджойнили)
int	main(int argc, char *argv[])
{
	t_data data;
	int i;

	data_init(&data, argc, argv);
	i = data.number_of_philosophers;
	// while(i > 0)
	// {
	// 	ptread_creat(тыры пыры, функция имитации жизни философа)
	// }перенести в pthreads_create наверно массив структур философов, я хз
		
	while (1)
		while (по кол-ву философов)
			if проверяет не умерли ли философы
				join all threads;
				destroy mutex
				чистим все
				return (0); в главном потоке*/
	//printf("%dhui%s\n", argc, *argv);
	printf("%d\n%d\n%d\n%d\n%d\n", data.number_of_philosophers, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.number_of_times_each_philosopher_must_eat);
	return (0);
} 