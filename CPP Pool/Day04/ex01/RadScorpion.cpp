/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) :
Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion( void )
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const & other):
Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	*this = other;
	return;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & other){
	if (this != &other)
	{
		Enemy::operator=(other);
	}
    return *this;
}
