/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:40:32 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 01:42:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <ctime>
#include <cstdlib>
#include <string>
#include "Zombie.hpp"

class	ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();

	void	setZombieType(std::string const zombieType);
	Zombie	*newZombie(std::string const name) const;
	Zombie	randomChump(void) const;


private:

	std::string	_zombieType;
};

#endif
