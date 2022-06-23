#include "../inc/philo.h"
#include "../inc/messages.h"
//разобраться с destroy(после того как все потоки заджойнили)
int	main(int argc, char *argv[])
{
	t_data data;
	int i;

	i = 0;
	if (data_init(&data, argc, argv) == FALSE)
		return (FALSE);
	if (mutex_create(&data) == FALSE)
		return (FALSE);
	if (create_philo(&data) == FALSE)//цикл инициирования массива структур философов
		return (FALSE);
	printf("count of philos - %d\n", data.number_of_philosophers);
	while (i < data.number_of_philosophers)
	{
		printf(" %d - philos_id, %d - i\n", data.philo_data[i].philos_id, i);
		i++;
	}
	if (create_philo_threads(&data) == FALSE)
		return (FALSE);//почистить
	exit(0);
	// while (1)
	// 	while (по кол-ву философов)
	// 		if проверяет не умерли ли философы - (текущее время - time_last_eating <= time_to_die)
	// 			join all threads;
	// 			destroy mutex
	// 			чистим все
	// 			return (0); в главном потоке*/
	//printf("%dhui%s\n", argc, *argv);
	//printf("%d\n%d\n%d\n%d\n%d\n", data.number_of_philosophers, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.number_of_times_each_philosopher_must_eat);
	return (0);
} 