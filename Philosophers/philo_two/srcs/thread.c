/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:21:52 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 15:39:09 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	check_if_dead(t_data *common)
{
	unsigned int	i;

	i = 0;
	sem_wait(common->dead_or_exit_sem);
	while (i < common->nb_of_philo && !common->dead)
	{
		sem_post(common->dead_or_exit_sem);
		if ((common->timestamp - common->last_meal_time[i]) > (int)common->die)
		{
			put_text(common, common->timestamp, i + 1, DEAD);
			sem_wait(common->dead_or_exit_sem);
			common->dead = 1;
			sem_post(common->dead_or_exit_sem);
		}
		i++;
		sem_wait(common->dead_or_exit_sem);
	}
	sem_post(common->dead_or_exit_sem);
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
		sem_wait(common->time_sem);
		common->timestamp = (int)timestamp(&common->begin, &now);
		if (previous_time != common->timestamp)
			previous_time = check_if_dead(common);
		sem_post(common->time_sem);
		usleep(50);
		sem_wait(common->dead_or_exit_sem);
		if (common->dead || common->thread_exit == (int)common->nb_of_philo)
			loop = 0;
		sem_post(common->dead_or_exit_sem);
	}
	return (0);
}

static void	algorithm_sleep_and_think(t_philo_i *philo)
{
	sem_wait(philo->common->time_sem);
	put_text(philo->common, philo->common->timestamp, philo->number, SLEEP);
	sem_post(philo->common->time_sem);
	ft_usleep(philo->common->sleep);
	sem_wait(philo->common->time_sem);
	put_text(philo->common, philo->common->timestamp, philo->number, THINK);
	sem_post(philo->common->time_sem);
	usleep(500);
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
	sem_wait(philo->common->dead_or_exit_sem);
	while (!philo->common->dead)
	{
		sem_post(philo->common->dead_or_exit_sem);
		algorithm_fork(philo);
		if (philo->nb_of_meal == philo->common->meal_nb)
		{
			sem_wait(philo->common->time_sem);
			put_text(philo->common, philo->common->timestamp,
						philo->number, FINISH);
			sem_post(philo->common->time_sem);
			sem_wait(philo->common->dead_or_exit_sem);
			philo->common->thread_exit++;
			sem_post(philo->common->dead_or_exit_sem);
			return (0);
		}
		algorithm_sleep_and_think(philo);
		sem_wait(philo->common->dead_or_exit_sem);
	}
	sem_post(philo->common->dead_or_exit_sem);
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
