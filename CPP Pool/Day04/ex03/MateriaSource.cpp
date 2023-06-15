/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		_theSource[i]= 0;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (_theSource[i])
		{
			delete (_theSource[i]);
			_theSource[i] = 0;
		}
	}
}

MateriaSource::MateriaSource( MateriaSource const & other){
	for (int i = 0; i < 4; i++)
	{
		if (other._theSource[i])
			_theSource[i] = other._theSource[i]->clone();
		else
			_theSource[i]= 0;
	}
	return;
}


MateriaSource & MateriaSource::operator=(MateriaSource const & other){
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_theSource[i])
			{
				delete (_theSource[i]);
				_theSource[i] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._theSource[i])
				_theSource[i] = other._theSource[i]->clone();
			else
				_theSource[i]= 0;
		}
	}
    return *this;
}

void MateriaSource::learnMateria(AMateria* newMateria){
	if (!newMateria)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_theSource[i])
		{
			_theSource[i] = newMateria;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (_theSource[i]->getType() == type)
			return (_theSource[i]->clone());
	}
	return (0);
}
