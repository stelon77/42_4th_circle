/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:35:23 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 00:20:24 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
public:
	HumanB(std::string const name);
	~HumanB();

	void attack(void) const;
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};


#endif