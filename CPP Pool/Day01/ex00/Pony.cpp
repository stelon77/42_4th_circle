/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 08:35:31 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 08:35:31 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string const name, int const age, std::string const color, std::string const announce) :
    _name(name), _age(age), _color(color), _announce(announce)
{
}

Pony::~Pony(void)
{
    std::cout << "my pony " << _name << " is destroyed...Rest in peace" << std::endl;
}

void Pony::ponyPresentation(void) const
{
    std::cout << "I'm " << _name << " a cute little pony of " << _age << " years old and I'm ";
    std::cout << _color << ". I should be on the " << _announce << std::endl;
}