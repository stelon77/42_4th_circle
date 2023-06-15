/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 10:41:02 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{}

AMateria::AMateria(std::string const & type):
_type(type), _xp(0) {}

AMateria::~AMateria(void) {}

AMateria::AMateria( AMateria const & other){
	*this = other;
	return;
}

AMateria & AMateria::operator=(AMateria const & other){
	if (this != &other)
	{
		_type = other._type;
		_xp = other._xp;
	}
    return *this;
}

std::string const & AMateria::getType( void ) const {
	return (_type);
}

unsigned int AMateria::getXP() const {
	return (_xp);
}

void AMateria::use(ICharacter& target){
	_xp += 10;
	(void)target;
}
