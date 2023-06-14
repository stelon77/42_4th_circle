/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:24:44 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 16:03:50 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** ------------destroy_semaphore-------------
**
** unlink puis detruits les differents semaphores
*/

void	destroy_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("writing");
	sem_unlink("eaten");
	sem_unlink("death");
	sem_close(data->forks_sem);
	sem_close(data->write_sem);
	sem_close(data->death_sem);
	sem_close(data->eaten_sem);
}

/*
** ------------destroy_data-------------
**
** free les elts de la structure commune
*/

int		destroy_data(t_data *data, int ret)
{
	destroy_semaphore(data);
	return (ret);
}
