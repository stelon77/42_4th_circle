/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 21:45:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** -------releasing_fork-----------
**
** ordre de prise des fourchettes en fonction du statut pair ou non
** affichage de la prise de fourchette
*/

void	taking_fork(t_philo_i *philo, int nb, int philos_nb)
{
	if (nb % 2)
	{
		pthread_mutex_lock(&philo->common->forks_mutex[nb - 1]);
		pthread_mutex_lock(&philo->common->time_mutex);
		put_text(philo->common, philo->common->timestamp, nb, FORK);
		pthread_mutex_unlock(&philo->common->time_mutex);
		pthread_mutex_lock(&philo->common->forks_mutex[nb % philos_nb]);
		pthread_mutex_lock(&philo->common->time_mutex);
		put_text(philo->common, philo->common->timestamp, nb, FORK);
		pthread_mutex_unlock(&philo->common->time_mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->common->forks_mutex[nb % philos_nb]);
		pthread_mutex_lock(&philo->common->time_mutex);
		put_text(philo->common, philo->common->timestamp, nb, FORK);
		pthread_mutex_unlock(&philo->common->time_mutex);
		pthread_mutex_lock(&philo->common->forks_mutex[nb - 1]);
		pthread_mutex_lock(&philo->common->time_mutex);
		put_text(philo->common, philo->common->timestamp, nb, FORK);
		pthread_mutex_unlock(&philo->common->time_mutex);
	}
}

/*
** -------releasing_fork-----------
**
** ordre de relachement des fourchettes en fonction du statut pair ou non
*/

void	releasing_fork(t_philo_i *philo, int nb, int philos_nb)
{
	if (nb % 2)
	{
		pthread_mutex_unlock(&philo->common->forks_mutex[nb % philos_nb]);
		pthread_mutex_unlock(&philo->common->forks_mutex[nb - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->common->forks_mutex[nb - 1]);
		pthread_mutex_unlock(&philo->common->forks_mutex[nb % philos_nb]);
	}
}

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
	taking_fork(philo, philo->number, philo->common->nb_of_philo);
	pthread_mutex_lock(&philo->common->time_mutex);
	if ((philo->common->timestamp -
			philo->common->last_meal_time[philo->number - 1])
				<= (int)philo->common->die)
	{
		philo->common->last_meal_time[philo->number - 1] =
			philo->common->timestamp;
		put_text(philo->common, philo->common->timestamp, philo->number, EAT);
	}
	pthread_mutex_unlock(&philo->common->time_mutex);
	ft_usleep(philo->common->eat);
	philo->nb_of_meal++;
	releasing_fork(philo, philo->number, philo->common->nb_of_philo);
	return (0);
}
