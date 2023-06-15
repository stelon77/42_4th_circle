/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

Fire::Fire( void ):
AMateria("fire")
{
}

Fire::~Fire( void )
{
}

Fire::Fire( Fire const & other) :
AMateria("fire")
{
	*this = other;
	return;
}


Fire & Fire::operator=(Fire const & other){
	if (this != &other)
		AMateria::operator=(other);
    return *this;
}

AMateria* Fire::clone() const{
	return (new Fire());
}

void Fire::use(ICharacter& target){
	AMateria::use(target);
	std::cout << "* shoots an fireball (3d6) at " << target.getName() << " *" << std::endl;//mettre nom target
}