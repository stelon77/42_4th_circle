/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:51:14 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/03 16:25:52 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
}


Brain::~Brain()
{
}

std::string Brain::identify(void) const{
	std::ostringstream oss;

	oss << "0x" << std::uppercase << std::hex << (long)this;
	return (oss.str());
}
