/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:53:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 16:05:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
** -un semaphore death pour debloquer le main (initialise a 0)
** -un semaphore eaten pour compter les philos ayant fini
*/

int		init_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("writing");
	sem_unlink("death");
	sem_unlink("eaten");
	data->forks_sem = sem_open("forks", O_CREAT, 0666, data->nb_of_philo / 2);
	if (data->forks_sem == SEM_FAILED)
		return (1);
	data->write_sem = sem_open("writing", O_CREAT, 0666, 1);
	if (data->write_sem == SEM_FAILED)
		return (1);
	data->death_sem = sem_open("death", O_CREAT, 0666, 0);
	if (data->death_sem == SEM_FAILED)
		return (1);
	data->eaten_sem = sem_open("eaten", O_CREAT, 0666, 0);
	if (data->eaten_sem == SEM_FAILED)
		return (1);
	return (0);
}

/*
** -------------initialize_data-------------
**
** initialise la structure de datas communes
** initialisation des semaphores
*/

int		initialize_data(t_data *data)
{
	if (init_semaphore(data))
		return (error_msg("semaphore initialization problem\n", 1));
	return (0);
}

/*
** -------------initialize_philo-------------
**
** initialise chaque philo envoye en thread
** en particulier transmet la structure de datas communes
*/

void	initialize_philo(t_philo_i *philo, t_data *data)
{
	philo->nb_of_meal = 0;
	philo->number = 0;
	philo->common = data;
}
