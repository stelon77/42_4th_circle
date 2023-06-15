/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:38:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 01:43:52 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string const type, std::string const name) : _type(type), _name(name){
}


Zombie::~Zombie(){
	std::cout << "zombie destroyed: " << _type << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." <<  std::endl;
}
