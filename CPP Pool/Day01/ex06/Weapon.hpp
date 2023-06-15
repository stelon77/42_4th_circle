/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:25:43 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/03 21:51:04 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string const type);
	~Weapon();

	std::string const &	getType(void) const;
	void setType (std::string const type);

private:
	std::string _type;
};




#endif