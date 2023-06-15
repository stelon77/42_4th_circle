/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ):
AMateria("ice")
{
}

Ice::~Ice( void )
{
}

Ice::Ice( Ice const & other) :
AMateria("ice")
{
	*this = other;
	return;
}


Ice & Ice::operator=(Ice const & other){
	if (this != &other)
		AMateria::operator=(other);
    return *this;
}

AMateria* Ice::clone() const{
	return (new Ice());
}

void Ice::use(ICharacter& target){
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;//mettre nom target
}