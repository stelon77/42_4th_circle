/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 15:37:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** -------algorithm_fork-----------
**
** prise des 2 fourchettes,
** verification absence de mort
** duree du repas
** incrementation nombre repas pris
** remise en place des fourchettes
*/

int		algorithm_fork(t_philo_i *philo)
{
	sem_wait(philo->common->forks_sem);
	sem_wait(philo->common->time_sem);
	put_text(philo->common, philo->common->timestamp, philo->number, FORK);
	put_text(philo->common, philo->common->timestamp, philo->number, FORK);
	sem_post(philo->common->time_sem);
	sem_wait(philo->common->time_sem);
	if ((philo->common->timestamp -
			philo->common->last_meal_time[philo->number - 1])
				<= (int)philo->common->die)
	{
		philo->common->last_meal_time[philo->number - 1] =
			philo->common->timestamp;
		put_text(philo->common, philo->common->timestamp, philo->number, EAT);
	}
	sem_post(philo->common->time_sem);
	ft_usleep(philo->common->eat);
	philo->nb_of_meal++;
	sem_post(philo->common->forks_sem);
	return (0);
}
