/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 13:43:04 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	int t;

	sem_wait(philo->common->forks_sem);
	put_text(philo->common, t_stamp(&philo->common->begin), philo->number,
				FORK);
	put_text(philo->common, t_stamp(&philo->common->begin), philo->number,
				FORK);
	t = t_stamp(&philo->common->begin);
	if ((t - philo->common->last_meal_time) <= (int)philo->common->die)
	{
		philo->common->last_meal_time = t;
		put_text(philo->common, t, philo->number, EAT);
	}
	ft_usleep(philo->common->eat);
	philo->nb_of_meal++;
	sem_post(philo->common->forks_sem);
	return (0);
}
