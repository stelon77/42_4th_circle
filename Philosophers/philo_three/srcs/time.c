/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:15:35 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/15 19:43:16 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** ------------timestamp-------------
**
** donne le timestamp en msec
*/

long int	timestamp(struct timeval *begin, struct timeval *now)
{
	struct timeval	diff;

	timersub(now, begin, &diff);
	return ((diff.tv_sec * 1000) + (diff.tv_usec / 1000));
}

/*
** ------------timestamp2-------------
**
** donne le timestamp en msec
** plus simple, utilise par philo 3
*/

long int	t_stamp(struct timeval *begin)
{
	struct timeval	diff;
	struct timeval	now;

	gettimeofday(&now, NULL);
	timersub(&now, begin, &diff);
	return ((diff.tv_sec * 1000) + (diff.tv_usec / 1000));
}

/*
** ------------ft_usleep-------------
**
** argument en msec
** un usleep plus precis.....
*/

void		ft_usleep(int msec)
{
	struct timeval	aim;
	struct timeval	actual;
	struct timeval	diff;

	gettimeofday(&aim, NULL);
	aim.tv_sec = aim.tv_sec + ((aim.tv_usec + (msec * 1000)) / 1000000);
	aim.tv_usec = (aim.tv_usec + (msec * 1000)) % 1000000;
	gettimeofday(&actual, NULL);
	timersub(&aim, &actual, &diff);
	while (diff.tv_sec > 0 || (diff.tv_sec == 0 && diff.tv_usec > 0))
	{
		usleep(50);
		gettimeofday(&actual, NULL);
		timersub(&aim, &actual, &diff);
	}
}
