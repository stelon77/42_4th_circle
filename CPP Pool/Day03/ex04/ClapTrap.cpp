/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:17:06 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:17:22 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap( void ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
	_maxEnergyPoints(1000), _level(1), _meleeAttackDamage(100), _rangedAttackDamage(100),
	_armorDamageReduction(100)
{
	std::cout << "Start bootup sequence. I'm a ClapTrap" << std::endl;
}

ClapTrap::ClapTrap( std::string const name ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
	_maxEnergyPoints(100), _level(1), _meleeAttackDamage(100), _rangedAttackDamage(100),
	_armorDamageReduction(100), _name(name)
{
	std::cout << "Start bootup sequence. I'm ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap( std::string const name, int hp, int maxhp, int ep, int maxep, int lvl, int mad, int rad, int adr):
	_hitPoints(hp),
	_maxHitPoints(maxhp),
	_energyPoints(ep),
	_maxEnergyPoints(maxep),
	_level(lvl),
	_meleeAttackDamage(mad),
	_rangedAttackDamage(rad),
	_armorDamageReduction(adr),
	_name(name)
{
	std::cout << "Start bootup sequence. I'm ClapTrap " << _name << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "HELP ME! HELP MEEEEE HEE HEE HEEE! HHHHHHHELP!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other){
	*this = other;
	std::cout << "Start bootup sequence. I'm ClapTrap " << _name << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other){
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

void	ClapTrap::rangedAttack(std::string const & target) const{
	std::cout << "CL4P-TP " << _name << " attacks " << target;
	std::cout << " at range, causing " << _rangedAttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) const{
	std::cout << "CL4P-TP " << _name << " attacks " << target;
	std::cout << " at melee, causing " << _meleeAttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
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
	std::cout << "Aaaaaarrghhhh !! " << _name << " is hit !!! " << lost << " damage taken ! ";
	if (_hitPoints > 0)
		std::cout << "But still alive, thanks to my armor ! " << _hitPoints << " hitpoints left" << std::endl;
	else
		std::cout << "Unless your repair me, I'm dead !! " << _hitPoints << " hitpoints left" << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount){
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << "Lookin' good, minion! I feel better with this reparation !! Now I have ";
	std::cout << _hitPoints << " hitpoints " << std::endl;
}
//
// void ClapTrap::afficher(){
// 	std::cout << "vie : " << _hitPoints << " energie : " << _energyPoints << std::endl;
// }
//

