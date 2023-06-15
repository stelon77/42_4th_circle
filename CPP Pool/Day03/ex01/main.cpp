/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:33:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/13 22:13:10 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	srand(time(0));

	std::cout << "\n-------FRAG TRAP -----------\n\n";

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

	std::cout << "\n-------SCAV TRAP -----------\n\n";

	ScavTrap *lolo = new ScavTrap("Scaver");
	lolo->meleeAttack("You");
	lolo->rangedAttack("BadGuy");
	lolo->takeDamage(60);
	lolo->takeDamage(55);
	lolo->beRepaired(8);
	lolo->beRepaired(100);
	lolo->challengeNewcomer("BadGuy");
	lolo->challengeNewcomer("EvilLord");
	lolo->challengeNewcomer("MiniMe");
	lolo->challengeNewcomer("Olga");
	lolo->challengeNewcomer("007");
	delete lolo;
	std::cout << "\n\n";


	return (0);
}