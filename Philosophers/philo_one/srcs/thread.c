/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:21:52 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 17:29:37 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	check_if_dead(t_data *common)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_lock(&common->dead_or_exit_mutex);
	while (i < common->nb_of_philo && !common->dead)
	{
		pthread_mutex_unlock(&common->dead_or_exit_mutex);
		if ((common->timestamp - common->last_meal_time[i]) > (int)common->die)
		{
			put_text(common, common->timestamp, i + 1, DEAD);
			pthread_mutex_lock(&common->dead_or_exit_mutex);
			common->dead = 1;
			pthread_mutex_unlock(&common->dead_or_exit_mutex);
		}
		i++;
		pthread_mutex_lock(&common->dead_or_exit_mutex);
	}
	pthread_mutex_unlock(&common->dead_or_exit_mutex);
	return (common->timestamp);
}

/*
** -----------thread_time----------
**
** argument = t_data
** la timeline
** modify timestamp
** each msec check if one of the philo is dead
** stops if one died or if all have enough eaten
*/

void		*thread_time(void *arg)
{
	t_data			*common;
	struct timeval	now;
	int				loop;
	int				previous_time;

	common = arg;
	loop = 1;
	previous_time = 0;
	while (loop)
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&common->time_mutex);
		common->timestamp = (int)timestamp(&common->begin, &now);
		if (previous_time != common->timestamp)
			previous_time = check_if_dead(common);
		pthread_mutex_unlock(&common->time_mutex);
		usleep(50);
		pthread_mutex_lock(&common->dead_or_exit_mutex);
		if (common->dead || common->thread_exit == (int)common->nb_of_philo)
			loop = 0;
		pthread_mutex_unlock(&common->dead_or_exit_mutex);
	}
	return (0);
}

static void	algorithm_sleep_and_think(t_philo_i *philo)
{
	pthread_mutex_lock(&philo->common->time_mutex);
	put_text(philo->common, philo->common->timestamp, philo->number, SLEEP);
	pthread_mutex_unlock(&philo->common->time_mutex);
	ft_usleep(philo->common->sleep);
	usleep(150);
	pthread_mutex_lock(&philo->common->time_mutex);
	put_text(philo->common, philo->common->timestamp, philo->number, THINK);
	pthread_mutex_unlock(&philo->common->time_mutex);
}

/*
** --------------thread_philo---------------
**
** argument : une structure t_philo_i
** boucle infinie tant que personne ne meurt
** choix des fourchettes
**  si nombre de repas requis atteint, on sort de table
**   et on incremente thread_exit qui indiquera a timeline
**   que tout le monde est sorti de table
** puis dodo et pensage...
*/

void		*thread_philo(void *arg)
{
	t_philo_i		*philo;

	philo = arg;
	pthread_mutex_lock(&philo->common->dead_or_exit_mutex);
	while (!philo->common->dead)
	{
		pthread_mutex_unlock(&philo->common->dead_or_exit_mutex);
		algorithm_fork(philo);
		if (philo->nb_of_meal == philo->common->meal_nb)
		{
			pthread_mutex_lock(&philo->common->time_mutex);
			put_text(philo->common, philo->common->timestamp,
						philo->number, FINISH);
			pthread_mutex_unlock(&philo->common->time_mutex);
			pthread_mutex_lock(&philo->common->dead_or_exit_mutex);
			philo->common->thread_exit++;
			pthread_mutex_unlock(&philo->common->dead_or_exit_mutex);
			return (0);
		}
		algorithm_sleep_and_think(philo);
		pthread_mutex_lock(&philo->common->dead_or_exit_mutex);
	}
	pthread_mutex_unlock(&philo->common->dead_or_exit_mutex);
	return (0);
}

/*
** --------------thread_creation---------------
**
** on demarre a T0
** creation de la timeline
** creation d'un thread pour chaque philosophe
** puis attente de la terminaison des differents threads
*/

int			thread_creation(t_philo_i *philo, t_data *data)
{
	int	i;

	i = -1;
	gettimeofday(&data->begin, NULL);
	if (pthread_create(&data->timeline, NULL, thread_time, data))
		return (error_msg("threadcreation error\n", 1));
	while (++i < (int)data->nb_of_philo)
	{
		if (pthread_create(&data->philothread[i], NULL,
								thread_philo, &philo[i]))
			return (error_msg("threadcreation error\n", 1));
	}
	i = -1;
	while (++i < (int)data->nb_of_philo)
		if (pthread_join(data->philothread[i], NULL))
			return (error_msg("threadjoin error\n", 1));
	if (pthread_join(data->timeline, NULL))
		return (error_msg("threadjoin error\n", 1));
	return (0);
}
