/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:18:22 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void ) : ClapTrap()
{
	std::cout << "Recompiling my combat code! Ninja !!" << std::endl;
}

NinjaTrap::NinjaTrap( std::string const name ) : ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "Recompiling my combat code! Ninja " << _name << " !!" << std::endl;
}

NinjaTrap::~NinjaTrap( void )
{
	std::cout << "- Are you god? Am I dead? NOOOOOOooooooo....." << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const & other){
	*this = other;
	std::cout << "Recompiling my combat code! Ninja " << _name << " !!" << std::endl;
	return;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
    return *this;
}

void	NinjaTrap::rangedAttack(std::string const & target) const{
	std::cout << "N1NJ4-TP " << _name << " attacks " << target;
	std::cout << " at range, causing " << _rangedAttackDamage << " points of damage!" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target) const{
	std::cout << "N1NJ4-TP " << _name << " attacks " << target;
	std::cout << " at melee, causing " << _meleeAttackDamage << " points of damage!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & clap){
	std::cout << "Ssshhhh...I'm invisible" << std::endl;
	clap.rangedAttack(_name);
	takeDamage(5);
	std::cout << "Ouch ! I said I'm INVISIBLE" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & frag){
	std::cout << "You call yourself a badass? You're only a frag...Take that !" << std::endl;
	frag.takeDamage(_meleeAttackDamage);
}

void	NinjaTrap::ninjaShoebox(ScavTrap & scav){
	std::cout << "Taste my shuriken, gatekeeper!" << std::endl;
	scav.takeDamage(_rangedAttackDamage);

}

void	NinjaTrap::ninjaShoebox(NinjaTrap & ninja){
	std::cout << "Take these, gorgeous, you'll feel better!" << std::endl;
	ninja.beRepaired(20);
}

// //
// void NinjaTrap::afficher(){
// 	std::cout << "vie : " << _hitPoints << " energie : " << _energyPoints << std::endl;
// }
// //