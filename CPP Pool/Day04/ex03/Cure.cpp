/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ):
AMateria("cure")
{
}

Cure::~Cure( void )
{
}

Cure::Cure( Cure const & other) :
AMateria("cure")
{
	*this = other;
	return;
}


Cure & Cure::operator=(Cure const & other){
	if (this != &other)
		AMateria::operator=(other);
    return *this;
}

AMateria* Cure::clone() const{
	return (new Cure());
}

void Cure::use(ICharacter& target){
	AMateria::use(target);
	std::cout << "* heals " << target.getName()  << "'s wounds *" << std::endl;//mettre nom target
}