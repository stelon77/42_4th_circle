/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:24:42 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:19:07 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void ) : ClapTrap(), NinjaTrap(), FragTrap(){
	std::cout << "Here we go again! SuperMe" << std::endl;
}

SuperTrap::SuperTrap( std::string const name ) : ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5), NinjaTrap(), FragTrap()
{
	std::cout << "Here we go again! Super" << _name << " !!" << std::endl;
}

SuperTrap::~SuperTrap( void )
{
	std::cout << "Aaaand…op…ugh…" << std::endl;
}

SuperTrap::SuperTrap( SuperTrap const & other){
	*this = other;
	std::cout << "Here we go again! copy of Super" << _name << " !!" << std::endl;
	return;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
    return *this;
}

void	SuperTrap::rangedAttack(std::string const & target) const{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target) const{
	NinjaTrap::meleeAttack(target);
}
// //
// void SuperTrap::afficher(){
// 	std::cout << "vie : " << _hitPoints << " energie : " << _energyPoints << std::endl;
// }
// //