/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:24:21 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 11:30:34 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"


Peon::Peon( void ) : Victim()
{
}

Peon::Peon( std::string name ): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon( void )
{
	std::cout << "Bleuark..." << std::endl;
}


Peon::Peon( Peon const & other) : Victim(){
	*this = other;
	std::cout <<  "Zog zog." << std::endl;
	return;
}


Peon & Peon::operator=(Peon const & other){
	if (this != &other)
	{
		Victim::operator=(other);
    }
    return *this;
}

void Peon::getPolymorphed( void ) const{
	std::cout << _name << " was just polymorphed into a pink pony!" << std::endl;
}


