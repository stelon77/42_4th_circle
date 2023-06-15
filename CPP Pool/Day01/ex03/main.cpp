/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 20:22:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 21:28:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	int nbOfZombies;

	srand(time(0));
	std::cout << "How many zombies in a horde ?: ";
	std::cin >> nbOfZombies;
	ZombieHorde horde = ZombieHorde(nbOfZombies);
	horde.announce();
	return (0);
}