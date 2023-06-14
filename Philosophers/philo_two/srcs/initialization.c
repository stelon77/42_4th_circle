/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:53:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 15:38:33 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** ---------initialisation.c--------
** initialise les donnes communes (data)
** puis remplis une structure philo i par philosophe,
** qui sera envoye au thread correspondant
**
** --------init_semaphore---------------
**
** initialise les differents semaphores
** -un semaphore pour 2 fourchettes
** -un semaphore lors de l'ecriture des lignes
** -un semaphore lors changement etat (mort ou fin des repas prevus)
** -un semaphore temps pour les changements ou la consultation du timestamp
*/

int			init_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("timing");
	sem_unlink("writing");
	sem_unlink("end");
	data->forks_sem = sem_open("forks", O_CREAT, 0666, data->nb_of_philo / 2);
	data->time_sem = sem_open("timing", O_CREAT, 0666, 1);
	data->write_sem = sem_open("writing", O_CREAT, 0666, 1);
	data->dead_or_exit_sem = sem_open("end", O_CREAT, 0666, 1);
	return (0);
}

/*
** -------------initialize_data-------------
**
** initialise la structure de datas communes
** dont -le tableau de thread
** 		-le tableau des timestamps du dernier repas
** puis initialisation des mutex
*/

int			initialize_data(t_data *data)
{
	int	i;

	i = -1;
	if (init_semaphore(data))
		return (1);
	data->philothread = (pthread_t *)malloc(sizeof(pthread_t)
		* (data->nb_of_philo));
	if (!data->philothread)
		return (error_msg("malloc error\n", 1));
	data->last_meal_time = (int *)malloc(sizeof(int) * data->nb_of_philo);
	if (!data->last_meal_time)
		return (error_msg("malloc error\n", 1));
	while (++i < (int)data->nb_of_philo)
		data->last_meal_time[i] = 0;
	return (0);
}

/*
** -------------initialize_philo-------------
**
** initialise chaque philo envoye en thread
** en particulier transmet la structure de datas communes
*/

t_philo_i	*initialize_philo(t_data *data, int n)
{
	t_philo_i	*philo;
	int			i;

	philo = NULL;
	i = 0;
	if (!(philo = (t_philo_i *)malloc((sizeof(t_philo_i) * (n)))))
		return (NULL);
	while (i < n)
	{
		philo[i].number = i + 1;
		philo[i].common = data;
		philo[i].nb_of_meal = 0;
		i++;
	}
	return (philo);
}
