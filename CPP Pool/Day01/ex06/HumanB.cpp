/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:37:30 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 00:19:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string const name): _name(name), _weapon(0)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void) const{
	std::cout << _name << " attacks with his ";
	std::cout << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
}
