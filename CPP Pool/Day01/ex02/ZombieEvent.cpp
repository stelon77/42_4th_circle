/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:39:49 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 01:42:39 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){

}

ZombieEvent::~ZombieEvent(){

}

void ZombieEvent::setZombieType(std::string const zombieType){
	_zombieType = zombieType;
}

Zombie* ZombieEvent::newZombie(std::string const name) const{
	return (new Zombie(_zombieType, name));
}

Zombie ZombieEvent::randomChump(void) const{
	std::string randomName;
	std::string vowel = "aeiouy";
	std::string consonant = "bcdfghjklmnpqrstvwxz";

	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			randomName += vowel[rand() % 6];
		else
			randomName += consonant[rand() % 20];
	}
	return (Zombie(_zombieType, randomName));
}


