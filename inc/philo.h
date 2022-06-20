#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h> //gettimeofday 
# include <pthread.h>

typedef struct s_data {
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	//mutex на защиту стандартного вывода
	t_philo_struct *philo_struct;
} t_data;

typedef struct s_philo_data {
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int philos_num;
	t_mutex *left;
	t_mutex *right;
	struct timeval;//int gettimeofday(struct timeval, 0)
	//tv_sec*1000 +tv_sec/1000;
	
} t_philo_struct;

int	data_init(t_data *data, int argc, char *argv[]);
//void *philo(void *data);
//utils
int	ft_philo_atoi(const char *str);
int	ft_isdigit(int a);

#endif