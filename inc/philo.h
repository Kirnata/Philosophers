/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:08:39 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:51:19 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 0
# define FALSE 1
# define INT_MAX 2147483647

typedef struct s_data		t_data;
typedef struct s_philo_data	t_philo_data;

struct s_philo_data {
	pthread_t		philos_thread;
	int				philos_id;
	int				full_meal;
	long long		last_eating;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
};

struct s_data {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				must_die;
	t_philo_data	*philo_data;
	pthread_mutex_t	*mtxs;
	pthread_mutex_t	*mutex_for_print;
	pthread_mutex_t	*mutex_for_check;
};

/*
INIT MAIN STRUCTURE
*/
int					data_init(t_data *data, int argc, char *argv[]);
int					fill_data(t_data *data, int argc, char *argv[]);
int					ft_errors_in_init(t_data *data);

/*
INIT AND FILL STRUCTURE OF EACH PHILO
*/
int					create_philo(t_data *data);
void				fill_philo_data(t_data *data, int i, int j);
int					create_philo_threads(t_data *data);

/*
ROUTINE FUNCTIONS
*/
void				*all_your_life(void *args);
int					execute_life_circle(t_philo_data *philo_data);
int					ft_eating(t_philo_data *philo_data);
int					ft_sleep(t_philo_data *philo_data);

/*
ALL ABOUT MUTEX
*/
int					mutex_create(t_data *data);
int					ft_mutex_init(t_data *data);
int					ft_mutex_unlock(t_data *data);
int					ft_mutex_destroy(t_data *data);

/*
CHECKER
*/
int					checker(t_data *data);
int					check_round(t_data *data, int *meal_count);
int					join_threads(t_data *data);

/*
TIME MAGIC
*/
long long			get_time(void);
long long			time_delta(long long last_time);

/*
UTILS
*/
int					ft_isdigit(int a);
int					ft_philo_atoi(const char *str);
int					ft_print(t_data *data, int i, char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_usleep(size_t ms_to_sleep, long long last_time);
void				philo_free(t_data *data);

#endif
