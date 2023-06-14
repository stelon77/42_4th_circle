/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:24:44 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 15:37:53 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** ------------destroy_semaphore-------------
**
** unlink puis detruits les differents semaphores
*/

void	destroy_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("timing");
	sem_unlink("writing");
	sem_unlink("end");
	sem_close(data->forks_sem);
	sem_close(data->time_sem);
	sem_close(data->write_sem);
	sem_close(data->dead_or_exit_sem);
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
	destroy_semaphore(data);
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
