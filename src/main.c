#include "../inc/philo.h"
#include "../inc/messages.h"
//разобраться с destroy(после того как все потоки заджойнили)
int	main(int argc, char *argv[])
{
	t_data data;
	int i;
	data_init(&data, argc, argv);
	i = mutex_create(&data);
	if (i == 1)
		return (1);
	printf("hui\n");
	//exit(0);
	i = create_philo(&data);//цикл инициирования массива структур философов
	if (i == 1)
		return (1);
	printf("hui2\n");
	//exit(0);
	printf("count of philos - %d\n", data.number_of_philosophers);
	i = 0;
	printf("hui3\n");
	// exit(0);
	while (i < data.number_of_philosophers)
	{
		printf(" %d - philos_num\n", data.philo_data[i].philos_num);
		i++;
	}
	printf("hui4\n");
	// exit(0);
	printf("hui5\n");
	i = create_philo_threads(&data);//запускаем потоки
	exit(0);
	if (i == 1)//почистить
		return (1);
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