/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:53:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 22:23:16 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** ---------initialisation.c--------
** initialise les donnes communes (data)
** puis remplis une structure philo i par philosophe,
** qui sera envoye au thread correspondant
**
** --------init_mutex---------------
**
** initialise les differents mutex
** -un mutex par fourchette
** -un mutex lors de l'ecriture des lignes
** -un mutex lors changement etat (mort ou fin des repas prevus)
** -un mutex temps pour les changements ou la consultation du timestamp
*/

int			init_mutex(t_data *data)
{
	int	i;

	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->forks_mutex)
		return (error_msg("malloc error\n", 1));
	i = -1;
	while (++i < (int)data->nb_of_philo)
		if (pthread_mutex_init(&data->forks_mutex[i], NULL))
			return (error_msg("mutex initialization problem\n", 1));
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (error_msg("mutex initialization problem\n", 1));
	if (pthread_mutex_init(&data->dead_or_exit_mutex, NULL))
		return (error_msg("mutex initialization problem\n", 1));
	if (pthread_mutex_init(&data->time_mutex, NULL))
		return (error_msg("mutex initialization problem\n", 1));
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
	data->philothread = (pthread_t *)malloc(sizeof(pthread_t)
		* (data->nb_of_philo));
	if (!data->philothread)
		return (error_msg("malloc error\n", 1));
	data->last_meal_time = (int *)malloc(sizeof(int) * data->nb_of_philo);
	if (!data->last_meal_time)
		return (error_msg("malloc error\n", 1));
	while (++i < (int)data->nb_of_philo)
		data->last_meal_time[i] = 0;
	if (init_mutex(data))
		return (1);
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
