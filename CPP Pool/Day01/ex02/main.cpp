/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:37:27 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 01:37:28 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent Zevent;

	srand(time(0));
	Zevent.setZombieType("chump");
	Zombie chump = Zevent.randomChump();
	chump.announce();
	Zevent.setZombieType("ghoul");
	Zombie *ghoul = Zevent.newZombie("Tino");
	ghoul->announce();
	delete (ghoul);
	Zevent.setZombieType("chump2");
	Zombie chump2 = Zevent.randomChump();
	chump2.announce();
	return (0);
}



