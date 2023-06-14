/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:47:29 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 22:13:21 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef enum	e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	FINISH
}				t_state;

typedef struct	s_data
{
	unsigned int	nb_of_philo;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	meal_nb;
	pthread_t		*philothread;
	int				*last_meal_time;
	pthread_mutex_t	*forks_mutex;
	int				thread_exit;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	dead_or_exit_mutex;
	int				dead;
	struct timeval	begin;
	pthread_t		timeline;
	int				timestamp;
}				t_data;

typedef struct	s_philo_i
{
	unsigned int	number;
	t_data			*common;
	unsigned int	nb_of_meal;
}				t_philo_i;

/*
** algo_fork.c
*/
void			taking_fork(t_philo_i *philo, int nb, int philos_nb);
void			releasing_fork(t_philo_i *philo, int nb, int philos_nb);
int				algorithm_fork(t_philo_i *philo);

/*
** ft_lib.c
*/
size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
void			ft_putstr30(char *s);
int				ft_isdigit(int c);
unsigned int	ft_atoi_philo(const char *str);

/*
** check_error.c
*/
int				check_error(t_data *data, int argc, char **argv);
int				error_msg(char *msg, int ret);
int				check_arg(t_data *data, char *str, int i);
int				str_is_digit(char *str);

/*
** time.c
*/
long int		timestamp(struct timeval *begin, struct timeval *now);
void			ft_usleep(int msec);

/*
** put_text.c
*/
int				put_text(t_data *data, int time, int philo, t_state state);

/*
** initialization.c
*/
int				init_mutex(t_data *data);
int				initialize_data(t_data *data);
t_philo_i		*initialize_philo(t_data *data, int n);

/*
** thread.c
*/
void			*thread_time(void *arg);
void			*thread_philo(void *arg);
int				thread_creation(t_philo_i *philo, t_data *data);

/*
** destroy.c
*/
int				destroy_data(t_data *data, int ret);
void			destroy_mutex(t_data *data);
int				destroy_philo(t_philo_i *philo, t_data *data, int ret);

#endif
