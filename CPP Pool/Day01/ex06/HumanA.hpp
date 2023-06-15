/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:38:17 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 00:21:51 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
public:
	HumanA(std::string const name, Weapon &weapon);
	~HumanA();

	void attack(void) const;


private:
	std::string _name;
	Weapon &_weapon;
};


#endif