/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:29:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/22 14:44:33 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*thread_eaten(void *arg)
{
	t_data			*data;
	unsigned int	i;

	data = arg;
	i = 0;
	while (i < data->nb_of_philo)
	{
		sem_wait(data->eaten_sem);
		i++;
	}
	sem_post(data->death_sem);
	return (0);
}

void	*thread_death(void *arg)
{
	t_philo_i		*philo;
	unsigned int	t;

	philo = arg;
	while (1)
	{
		t = t_stamp(&philo->common->begin);
		if (t > (philo->common->die + philo->common->last_meal_time))
		{
			put_text(philo->common, t, philo->number, DEAD);
			sem_post(philo->common->death_sem);
			return (0);
		}
		ft_usleep(1);
	}
}

int		philo_process(t_philo_i *philo, int nb)
{
	philo->number = nb;
	if (pthread_create(&philo->common->timeline, NULL, thread_death, philo))
		exit(error_msg("threadcreation error\n", EXIT_FAILURE));
	if (pthread_detach(philo->common->timeline))
		exit(error_msg("threaddetach error\n", EXIT_FAILURE));
	while (1)
	{
		algorithm_fork(philo);
		if (philo->nb_of_meal == philo->common->meal_nb)
		{
			put_text(philo->common, t_stamp(&philo->common->begin), nb, FINISH);
			sem_post(philo->common->eaten_sem);
			exit(EXIT_SUCCESS);
		}
		put_text(philo->common, t_stamp(&philo->common->begin), nb, SLEEP);
		ft_usleep(philo->common->sleep);
		put_text(philo->common, t_stamp(&philo->common->begin), nb, THINK);
	}
	return (0);
}

int		clean_return(t_data *data, pid_t *pid)
{
	int i;

	i = -1;
	while (++i < (int)data->nb_of_philo)
		kill(pid[i], SIGINT);
	i = -1;
	while (++i < (int)data->nb_of_philo)
		sem_post(data->eaten_sem);
	if (pthread_join(data->has_enought_eaten, NULL))
		return (clean_pid("threadjoin error\n", 1, pid));
	return (0);
}

/*
** --------------thread_and_process_creation---------------
**
** on demarre a T0
** creation de la timeline
** creation d'un processus pour chaque philosophe
** puis attente de la fin (mort ou tous mange) pour kill tous les processus
*/

int		processus_creation(t_philo_i *philo, t_data *data)
{
	int		i;
	pid_t	*pid;

	i = -1;
	if (!(pid = (pid_t *)malloc(sizeof(pid_t) * data->nb_of_philo)))
		return (error_msg("malloc error\n", 1));
	if (pthread_create(&data->has_enought_eaten, NULL, thread_eaten, data))
		return (clean_pid("threadcreation error\n", 1, pid));
	gettimeofday(&data->begin, NULL);
	while (++i < (int)data->nb_of_philo)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (clean_pid("process creation error\n", 1, pid));
		if (!pid[i])
			philo_process(philo, i + 1);
	}
	sem_wait(data->death_sem);
	if (clean_return(data, pid))
		return (1);
	free(pid);
	return (0);
}
