/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:38:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 21:29:45 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string const type, std::string const name) : _type(type), _name(name){
}


Zombie::~Zombie(){
	std::cout << "zombie destroyed: " << _name << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." <<  std::endl;
}

void	Zombie::setType(std::string const type){
	_type = type;
}

void	Zombie::setName(std::string const name){
	_name = name;
}