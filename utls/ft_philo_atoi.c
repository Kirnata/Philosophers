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
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (number > INT_MAX || (!ft_isdigit(str[i]) && str[i] != '\0'))
		return (0);
	return ((int)(number));
}