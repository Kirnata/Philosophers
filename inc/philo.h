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
	t_philo_data *philo_data;
} t_data;

typedef struct s_mutex
{
	t_mutex *p_mutex;
} t_mutex;

typedef struct s_philo_data {
	pthread_t philos_thread;
	int philos_num;
	struct timeval;//int gettimeofday(struct timeval, 0)
	//tv_sec*1000 +tv_sec/1000;
	int last_eating;
	int	must_die;
	int right_fork;
	int left_fork;
} t_philo_data;

int	data_init(t_data *data, int argc, char *argv[]);
int	create_philo(t_data *data);
fill_philo_data(t_data *data, int i, int j);
//void *all_your_life(void *data)
//utils
int	ft_philo_atoi(const char *str);
int	ft_isdigit(int a);

#endif