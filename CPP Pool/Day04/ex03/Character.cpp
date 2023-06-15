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

Character::Character( std::string const name ):
_name(name)
{
	for (int i = 0; i< 4; i++)
		_inventory[i] = 0;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = 0;
		}
}


Character::Character( Character const & other):
_name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	return;
}

Character & Character::operator=(Character const & other){
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
			if (_inventory[i])
				delete (_inventory[i]);
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
    return *this;
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m){
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	return ;

}
void Character::unequip(int idx){
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = 0;
}
void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx]->use(target);
}
