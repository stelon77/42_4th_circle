/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:24:34 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 08:31:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator( void ) :
ISpaceMarine()
{
	std::cout << "* teleports from space *" << std::endl;
}


AssaultTerminator::AssaultTerminator( AssaultTerminator const & other){
	*this = other;
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator( void )
{
		std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & other){
	(void)other;
	return *this;
}

ISpaceMarine* AssaultTerminator::clone() const{
	return (new AssaultTerminator());
}

void AssaultTerminator::battleCry() const{
	std::cout << "This code is unclean. PURIFY IT!" <<std::endl;
}

void AssaultTerminator::rangedAttack() const{
	std::cout << "* does nothing *" <<std::endl;
}

void AssaultTerminator::meleeAttack() const{
	std::cout << "* attacks with chainfists *" <<std::endl;
}