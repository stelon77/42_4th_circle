/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 18:59:50 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
	_maxEnergyPoints(50), _level(1), _meleeAttackDamage(20), _rangedAttackDamage(15),
	_armorDamageReduction(3)
{
	std::cout << "Ha-HA! I am ALIIIIIVE!" << std::endl;
}

ScavTrap::ScavTrap( std::string const name ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
	_maxEnergyPoints(50), _level(1), _meleeAttackDamage(20), _rangedAttackDamage(15),
	_armorDamageReduction(3), _name(name)
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
		_hitPoints = other._hitPoints;
		_maxHitPoints = other._maxHitPoints;
		_energyPoints = other._energyPoints;
		_maxEnergyPoints = other._maxEnergyPoints;
		_level = other._level;
		_meleeAttackDamage = other._meleeAttackDamage;
		_rangedAttackDamage = other._rangedAttackDamage;
		_armorDamageReduction = other._armorDamageReduction;
		_name = other._name;
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

void	ScavTrap::takeDamage(unsigned int amount){
	int lost;

	lost = amount - _armorDamageReduction;
	if (lost <= 0)
	{
		std::cout << "a Minion tried to damage ME...but didn't even pass the armor" << std::endl;
		return;
	}
	_hitPoints -= lost;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "Aaaaaarrghhhh !! SC4V-TP " << _name << " is hit !!! " << lost << " damage taken ! ";
	if (_hitPoints > 0)
		std::cout << "But still alive, thanks to my armor ! " << _hitPoints << " hitpoints left" << std::endl;
	else
		std::cout << "Unless your repair me, I'm dead !! " << _hitPoints << " hitpoints left" << std::endl;
	return;
}

void	ScavTrap::beRepaired(unsigned int amount){
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << "Lookin' good, minion! I feel better with this reparation !! Now I have ";
	std::cout << _hitPoints << " hitpoints " << std::endl;
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




