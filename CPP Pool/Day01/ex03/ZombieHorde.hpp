/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:27:29 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 21:27:30 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

class ZombieHorde
{
public:
	ZombieHorde();
	ZombieHorde(int const n);
	~ZombieHorde();

	void	announce(void) const;

private:
	std::string _getRandomName(void) const;

	int	const	 _zombieNumber;
	Zombie		*horde;
};

#endif
