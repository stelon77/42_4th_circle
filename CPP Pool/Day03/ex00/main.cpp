/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:33:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/13 22:01:47 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{


	srand(time(0));

	std::cout << "\nn-------FRAG TRAP -----------\n\n";

	FragTrap *lol = new FragTrap("Frogger");
	lol->meleeAttack("You");
	lol->rangedAttack("BadGuy");
	lol->takeDamage(60);
	lol->takeDamage(55);
	lol->beRepaired(8);
	lol->beRepaired(100);
	lol->vaulthunter_dot_exe("BadGuy");
	lol->vaulthunter_dot_exe("EvilLord");
	lol->vaulthunter_dot_exe("MiniMe");
	lol->vaulthunter_dot_exe("Olga");
	lol->vaulthunter_dot_exe("007");
	delete lol;
	std::cout << "\n\n";

	return (0);
}