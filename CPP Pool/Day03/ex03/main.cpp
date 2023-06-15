/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:10:54 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/13 22:51:30 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

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

	std::cout << "\n-------CLAP TRAP -----------\n";
	ClapTrap clap("Clap");
	std::cout << "\n-------FRAG TRAP -----------\n";
	FragTrap frag("frag");
	std::cout << "\n-------SCAV TRAP -----------\n";
	ScavTrap scav("scav");
	std::cout << "\n-------NINJA TRAP -----------\n";

	NinjaTrap ninja1("ninja1");
	NinjaTrap ninja2("ninja2");
	ninja2.meleeAttack("007");
	ninja2.rangedAttack("OSS117");
	ninja2.takeDamage(30);
	ninja2.beRepaired(8);
	ninja1.ninjaShoebox(ninja2);
	ninja1.ninjaShoebox(scav);
	ninja1.ninjaShoebox(frag);
	ninja1.ninjaShoebox(clap);

	std::cout << "\n-------Destruction -----------\n";

	return (0);

}