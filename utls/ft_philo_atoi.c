#include "../inc/philo.h"
#include "../inc/messages.h"

int	ft_philo_atoi(const char *str)
{	
	long	i;
	long	number;

	i = 0;
	number = 0;
	if (str[i] != '\0' && str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			printf(ERROR_VALID_ARGS);
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	//проверка на переполнение
	return ((int)(number));
}