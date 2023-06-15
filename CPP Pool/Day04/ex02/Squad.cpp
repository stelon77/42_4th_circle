/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:24:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 08:26:58 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad( void ):
ISquad(), _count(0), _unit(0)
{
}

Squad::~Squad( void )
{
	for (int i = 0; i < _count; i++)
		delete _unit[i];
	delete [] _unit;
}

Squad::Squad( Squad const & other):
_count(other._count)
{
	_unit = new ISpaceMarine* [_count];
	for (int i = 0; i < _count; i++)
		_unit[i] = other._unit[i]->clone();
	return;
}

Squad & Squad::operator=(Squad const & other){
	if (this != &other)
	{

		for (int i = 0; i < _count; i++)
			delete _unit[i];
		delete [] _unit;
		_count =  other._count;
		_unit = new ISpaceMarine* [_count];
		for (int i = 0; i < _count; i++)
			_unit[i] = other._unit[i]->clone();
	}
    return *this;
}

int Squad::getCount() const{
	return (_count);
}

ISpaceMarine* Squad::getUnit(int nb) const{
	if (nb < 0 || nb >= _count || _count == 0)
		return (0);
	return _unit[nb];
}

int Squad::push(ISpaceMarine* soldier){
	ISpaceMarine** temp;

	if (!soldier)
		return (_count);
	if (!_unit)
	{
		_unit = new ISpaceMarine* [1];
		_unit[0] = soldier;
		return (_count = 1);
	}
	for (int i = 0; i < _count; i++)
		if (_unit[i] == soldier)
			return (_count);
	temp = _unit;
	_unit = new ISpaceMarine* [_count + 1];
	for (int i = 0; i < _count; i++)
		_unit[i] =  temp[i];
	_unit[_count] = soldier;
	delete [] temp;
	_count++;
	return (_count);
}
