/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:38:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/22 14:39:26 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	error_msg(char *msg, int ret)
{
	ft_putstr(msg);
	return (ret);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' && str[1])
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

/*
** ----------check_arg-------------
**
** mets les arguments dans la structure
** renvoie erreur si arguments pas dans la plage
*/

int	check_arg(t_data *data, char *str, int i)
{
	unsigned int	n;

	n = ft_atoi_philo(str);
	if (!(n))
		return (0);
	if (i == 1)
		data->nb_of_philo = n;
	else if (i == 2 && n)
		data->die = n;
	else if (i == 3 && n)
		data->eat = n;
	else if (i == 4 && n)
		data->sleep = n;
	else if (i == 5 && n)
		data->meal_nb = n;
	return (1);
}

/*
** ----------check_error-------------
**
** verifie si donnees sont valides
*/

int	check_error(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (error_msg("bad number of arguments\n", 1));
	while (i < argc)
	{
		if (!(str_is_digit(argv[i])))
			return (error_msg("arguments should be positive numbers\n", 1));
		if (!(check_arg(data, argv[i], i)))
			return (error_msg("arguments between 1 and +4 294 967 295\n", 1));
		i++;
	}
	if (data->nb_of_philo < 2)
		return (error_msg("we need at least 2 philosophers\n", 1));
	return (0);
}

int	clean_pid(char *msg, int ret, pid_t *pid)
{
	if (pid)
	{
		free(pid);
		pid = NULL;
	}
	return (error_msg(msg, ret));
}
