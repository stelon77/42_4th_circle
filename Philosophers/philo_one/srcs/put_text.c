/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:05:19 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/21 13:32:12 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static char	*put_state(t_state state)
{
	if (state == FORK)
		return ("has taken a fork");
	if (state == SLEEP)
		return ("is sleeping");
	if (state == EAT)
		return ("is eating");
	if (state == THINK)
		return ("is thinking");
	if (state == DEAD)
		return ("died");
	if (state == FINISH)
		return ("has finished");
	return (NULL);
}

static void	init_line(char *line)
{
	int	i;

	i = -1;
	while (i++ < 29)
		line[i] = ' ';
	line[29] = '\n';
	line[30] = '\0';
}

static void	fill_line(char *line, int stamp, int nb, t_state state)
{
	int		i;
	char	*text;

	i = 6;
	if (!stamp)
		line[6] = '0';
	while (stamp)
	{
		line[i] = (stamp % 10) + '0';
		stamp = stamp / 10;
		i--;
	}
	i = 11;
	while (nb)
	{
		line[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	text = put_state(state);
	i = -1;
	while (text[++i])
		line[13 + i] = text[i];
}

/*
** -----------put_text-------------
**
** optimisation de l'ecriture de la ligne
** un seul appel a write
** protection de l'ecriture si un philo est mort
*/

int			put_text(t_data *data, int time, int philo, t_state state)
{
	char			line[31];

	if (time >= 10000000)
		return (error_msg("over 10 000 seconds simulation not supported\n", 1));
	init_line(line);
	fill_line(line, time, philo, state);
	pthread_mutex_lock(&data->write_mutex);
	pthread_mutex_lock(&data->dead_or_exit_mutex);
	if (!data->dead)
		ft_putstr30(line);
	pthread_mutex_unlock(&data->dead_or_exit_mutex);
	pthread_mutex_unlock(&data->write_mutex);
	return (0);
}
