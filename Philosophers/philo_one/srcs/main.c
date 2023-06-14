/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:03:04 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 22:58:28 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char *argv[])
{
	t_philo_i	*philo;
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	if (check_error(&data, argc, argv))
		return (1);
	if (initialize_data(&data))
		return (destroy_data(&data, 1));
	if (!(philo = initialize_philo(&data, data.nb_of_philo)))
		return (destroy_data(&data, 1));
	if (thread_creation(philo, &data))
		return (destroy_philo(philo, &data, 1));
	return (destroy_philo(philo, &data, 0));
}
