/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:24:21 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 11:30:34 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Alien.hpp"


Alien::Alien( void ) : Victim()
{
}

Alien::Alien( std::string name ): Victim(name)
{
	std::cout << "Truth is elsewhere" << std::endl;
}

Alien::~Alien( void )
{
	std::cout << "We'll come back, Human!" << std::endl;
}


Alien::Alien( Alien const & other) : Victim(){
	*this = other;
	std::cout <<  "Truth is elsewhere" << std::endl;
	return;
}


Alien & Alien::operator=(Alien const & other){
	if (this != &other)
	{
		Victim::operator=(other);
    }
    return *this;
}

void Alien::getPolymorphed( void ) const{
	std::cout << _name << " was just polymorphed into a cute Human" << std::endl;
}


