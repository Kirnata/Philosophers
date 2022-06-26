#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h> //gettimeofday 
# include <pthread.h>

// typedef struct s_mutex
// {
// 	t_mutex p_mutex;
// 	//наверно что то еще нужно будет
// } t_mutex;

# define TRUE 0
# define FALSE 1
# define INT_MAX 2147483647

typedef struct s_data t_data;
typedef struct s_philo_data t_philo_data;

// typedef struct timeval {
// 	long tv_sec;
// 	long tv_usec;
// };

struct s_philo_data {
	pthread_t philos_thread;
	int philos_id;//int gettimeofday(struct timeval, 0)
	//tv_sec*1000 + tv_sec/1000 получать типо текущее время
	int full_meal;
	long long last_eating;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	t_data	*data;
};

struct s_data {
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	int	must_die;
	int	start_time;
	t_philo_data *philo_data;
	pthread_mutex_t *mtxs;
	pthread_mutex_t *mutex_for_print;
	// long long time_start_program;
};


int	data_init(t_data *data, int argc, char *argv[]);
//int	print_init_errors(t_data *data);
void fill_philo_data(t_data *data, int i, int j);
int	create_philo(t_data *data);
int	create_philo_threads(t_data *data);
//routine funcs
void *all_your_life(void *args);
int	execute_life_circle(t_philo_data *philo_data);
int ft_already_dead(t_philo_data *philo_data);
int join_threads(t_data *data);
//utils
int	ft_philo_atoi(const char *str);
int	ft_isdigit(int a);
int	mutex_create(t_data *data);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_print(pthread_mutex_t *mutex_for_print, int i, char *str);
//time
long long	get_time();
long long	time_delta(long long last_time);
void ft_usleep(size_t ms_to_sleep, long long last_time);
//cehck
int checker(t_data *data);
#endif