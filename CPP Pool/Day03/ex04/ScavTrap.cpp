/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:18:46 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap(){
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "Ha-HA! I am ALIIIIIVE!" << std::endl;
}

ScavTrap::ScavTrap( std::string const name ) :
ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3)
{
	std::cout << "Ha-HA! I am ALIIIIIVE! I'm the GREAT " << _name << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "Fatal errorrrrrrrrrrrrr…" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & other){
	*this = other;
	std::cout << "Ha-HA! I am ALIIIIIVE! I'm the GREAT " << _name << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
    return *this;
}

void	ScavTrap::rangedAttack(std::string const & target) const{
	std::cout << "SC4V-TP " << _name << " attacks " << target;
	std::cout << " at range, causing " << _rangedAttackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) const{
	std::cout << "SC4V-TP " << _name << " attacks " << target;
	std::cout << " at melee, causing " << _meleeAttackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) const{
	std::cout << "SC4V-TP " << _name << " welcomes " << target;
	std::cout << " : " << _challenges[rand() % 5] << std::endl;
}

std::string ScavTrap::_challenges[5] = {
	"Hello, Darlin', let's play Rock-Paper-Scissors",
	"Did you find the Vault yet? No ? Come back when you found it!",
	"Hey, check me out everybody! I'm dancin', I'm dancin'! ...Hey Sucker! Dance battle!",
	"We've really come a long way, haven't we, minion? And you're still just as loyal as ever! Who's a good minion? You are! Yes you are! Prove me you are!",
	"Just point me in the right direction!"
};

// //
// void ScavTrap::afficher(){
// 	std::cout << "vie : " << _hitPoints << " energie : " << _energyPoints << std::endl;
// }
// //


