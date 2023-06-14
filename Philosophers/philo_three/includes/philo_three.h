/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:47:29 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/22 11:31:52 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

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
	pthread_t		timeline;
	pthread_t		has_enought_eaten;
	int				last_meal_time;
	int				eaten_exit;
	sem_t			*forks_sem;
	sem_t			*write_sem;
	sem_t			*death_sem;
	sem_t			*eaten_sem;
	struct timeval	begin;
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
int				clean_pid(char *msg, int ret, pid_t *pid);

/*
** time.c
*/
long int		timestamp(struct timeval *begin, struct timeval *now);
void			ft_usleep(int msec);
long int		t_stamp(struct timeval *begin);

/*
** put_text.c
*/
int				put_text(t_data *data, int time, int philo, t_state state);

/*
** initialization.c
*/
int				init_semaphore(t_data *data);
int				initialize_data(t_data *data);
void			initialize_philo(t_philo_i *philo, t_data *data);

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
void			destroy_semaphore(t_data *data);

/*
** processus.c
*/
int				processus_creation(t_philo_i *philo, t_data *data);
int				philo_process(t_philo_i *philo, int nb);
void			*thread_death(void *arg);
void			*thread_eaten(void *arg);

#endif
