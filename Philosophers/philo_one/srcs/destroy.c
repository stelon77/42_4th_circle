/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:24:44 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 22:53:41 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** ------------destroy_mutex-------------
**
** detruits les differents mutex
** et free le tableau de mutex forks
*/

void	destroy_mutex(t_data *data)
{
	int	i;

	if (data->forks_mutex)
	{
		i = -1;
		while (++i < (int)data->nb_of_philo)
			pthread_mutex_destroy(&data->forks_mutex[i]);
		free(data->forks_mutex);
		data->forks_mutex = NULL;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->dead_or_exit_mutex);
	pthread_mutex_destroy(&data->time_mutex);
}

/*
** ------------destroy_data-------------
**
** free les elts de la structure commune
** a appeler avant de detruire le tableau de philosophes
*/

int		destroy_data(t_data *data, int ret)
{
	if (data->philothread)
	{
		free(data->philothread);
		data->philothread = NULL;
	}
	if (data->last_meal_time)
	{
		free(data->last_meal_time);
		data->last_meal_time = NULL;
	}
	destroy_mutex(data);
	return (ret);
}

/*
** ------------destroy_philo-------------
**
** free le tableau de philosophes
** a appeler en dernier
*/

int		destroy_philo(t_philo_i *philo, t_data *data, int ret)
{
	destroy_data(data, 0);
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
	return (ret);
}
