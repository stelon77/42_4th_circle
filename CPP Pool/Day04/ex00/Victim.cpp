/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 07:21:21 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 11:04:42 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim( void )
{
}

Victim::Victim( std::string name ):
	_name(name)
{
	std::cout << "Some random victim called " <<_name << " just appeared!" << std::endl;
}

Victim::~Victim( void )
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}


Victim::Victim( Victim const & other){
	*this = other;
	std::cout << "Some random victim called " <<_name << " just appeared!" << std::endl;
	return;
}


Victim & Victim::operator=(Victim const & other){
	if (this != &other)
	{
		_name = other._name;
    }
    return *this;
}

std::string Victim::getName( void ) const{
	return _name;
}

void Victim::getPolymorphed( void ) const{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}


std::ostream & operator<<(std::ostream & out, Victim const & s){
	return (out << "I am " << s.getName() << " and I like otters!" << std::endl);
}
