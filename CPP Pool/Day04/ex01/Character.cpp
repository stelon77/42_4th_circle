/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void )
{
}

Character::Character(std::string const & name):
_name(name), _ap(40), _weapon(0)
{
}

Character::~Character( void )
{
}

Character::Character( Character const & other){
	*this = other;
	return;
}


Character & Character::operator=(Character const & other){
	if (this != &other)
	{
		_name = other._name;
		_ap = other._ap;
		_weapon = other._weapon;
	}
    return *this;
}

void Character::recoverAP( void ){
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
	std::cout << _name << " recovers AP! He got now " << _ap << " AP" << std::endl;
	return ;
}

void Character::equip(AWeapon* weapon){
	_weapon = weapon;
}

void Character::attack(Enemy* enemy){
	if (_weapon == 0)
		return ;
	if (_ap < _weapon->getAPCost())
	{
		std::cout << "Not enough AP to attack!" << std::endl;
		return ;
	}
	_ap -= _weapon->getAPCost();
	std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (enemy->getHP() <= 0)
	{
		delete (enemy);
	}
	return ;
}

std::string const & Character::getName( void ) const{
	return (_name);
}

int Character::getActionPoints( void) const{
	return (_ap);
}

AWeapon* Character::getWeapon( void ) const{
	return (_weapon);
}


std::ostream & operator<<(std::ostream & out, Character const & hero){
	out << hero.getName() << " has " << hero.getActionPoints() << " AP and ";
	if (hero.getWeapon() == 0)
		return (out << "is unarmed" << std::endl);
	return (out << "wields a " << hero.getWeapon()->getName() << std::endl);
}
