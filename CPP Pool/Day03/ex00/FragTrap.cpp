/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 18:59:33 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
	_maxEnergyPoints(100), _level(1), _meleeAttackDamage(30), _rangedAttackDamage(20),
	_armorDamageReduction(5)
{
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m invisible" << std::endl;
}

FragTrap::FragTrap( std::string const name ) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
	_maxEnergyPoints(100), _level(1), _meleeAttackDamage(30), _rangedAttackDamage(20),
	_armorDamageReduction(5), _name(name)
{
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m ";
	std::cout << _name << " and I’m INVISIBLE! " << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "Minion, what have you DONE?!...DESTRUCTION !!!" << std::endl;
}

FragTrap::FragTrap( FragTrap const & other){
	*this = other;
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m ";
	std::cout << _name << " and I’m INVISIBLE! " << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & other){
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

void	FragTrap::rangedAttack(std::string const & target) const{
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << " at range, causing " << _rangedAttackDamage << " points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const{
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << " at melee, causing " << _meleeAttackDamage << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount){
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
	std::cout << "Aaaaaarrghhhh !! FR4G-TP " << _name << " is hit !!! " << lost << " damage taken ! ";
	if (_hitPoints > 0)
		std::cout << "But still alive, thanks to my armor ! " << _hitPoints << " hitpoints left" << std::endl;
	else
		std::cout << "Unless your repair me, I'm dead !! " << _hitPoints << " hitpoints left" << std::endl;
	return;
}

void	FragTrap::beRepaired(unsigned int amount){
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << "Thanks Minion !!  I feel better with this reparation !! Now I have ";
	std::cout << _hitPoints << " hitpoints " << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target){
	if (_energyPoints < 25)
	{
		std::cout << "I'm out of energy !! Damn you, " << target << "!!" << std::endl;
		return;
	}
	else
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target;
		std::cout << " and shouts : " << _attackShout[rand() % 5] << std::endl;
	}
}

std::string FragTrap::_attackShout[5] = {
	"They're weak to bullets, let'shoot them",
	"You've earned it !! FIRESTOOOORM !! See you in hell, sucker !!",
	"Blow 'em apart!",
	"Hey, bandits -- FREEZE! AHAHAHAHAHAHAHAH! ",
	"There's oil everywherrrre…IGNITION !!! "
};




