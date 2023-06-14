/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:26:54 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/03/08 21:50:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t			ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

/*
** -------ft_putstr30-----------
**
** un put str pour un string de 30
** (evite les boucles de strlen)
*/

void			ft_putstr30(char *s)
{
	if (!s)
		return ;
	write(1, s, 30);
}

int				ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

/*
** -------ft_atoi_philo-----------
**
** un atoi modifie pour philo
*/

unsigned int	ft_atoi_philo(const char *str)
{
	int				i;
	long int		nbr;
	unsigned int	ret;

	i = 0;
	nbr = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (nbr > 4294967295)
		return (0);
	ret = (unsigned int)nbr;
	return (ret);
}
