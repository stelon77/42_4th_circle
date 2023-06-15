/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:23:49 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/17 16:06:29 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine( void ) :
ISpaceMarine()
{
	std::cout <<  "Tactical Marine ready for action !" << std::endl;
}

TacticalMarine::~TacticalMarine( void )
{
		std::cout << "Aaargh ..." << std::endl;

}

TacticalMarine::TacticalMarine( TacticalMarine const & other){
	*this = other;
	std::cout <<  "Tactical Marine ready for action !" << std::endl;
	return;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & other){
	(void)other;
	return *this;
}

ISpaceMarine* TacticalMarine::clone() const{
	return(new TacticalMarine());
}

void TacticalMarine::battleCry() const{
	std::cout << "For the Holy PLOT !" <<std::endl;
}

void TacticalMarine::rangedAttack() const{
	std::cout <<  "* attacks with a bolter *" <<std::endl;
}

void TacticalMarine::meleeAttack() const{
	std::cout << "* attacks with a chainsword *" <<std::endl;
}