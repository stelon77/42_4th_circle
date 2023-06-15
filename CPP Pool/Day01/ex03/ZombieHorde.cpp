/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:27:19 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 21:27:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(): _zombieNumber(0){

}

ZombieHorde::ZombieHorde(int const n): _zombieNumber(n){
	horde = new Zombie[n];

	for (int i = 0; i < _zombieNumber; i++)
	{
		horde[i].setName(_getRandomName());
		horde[i].setType("zombie from the HOOOOORRRDE!!!");
	}
}

ZombieHorde::~ZombieHorde(){
	delete [] horde;
	std::cout << "the HORDE is destructed, thanks to C++ !" << std::endl;
}

void	ZombieHorde::announce(void) const{


	for (int i = 0; i < _zombieNumber; i++)
	{
		horde[i].announce();
	}

}

std::string ZombieHorde::_getRandomName(void) const{
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
	return (randomName);
}
