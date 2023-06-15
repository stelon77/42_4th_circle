/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 18:01:14 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
public:
	Character(std::string const & name);
	Character( Character const & other);
	Character & operator=(Character const & other);
	virtual ~Character( void );

	void recoverAP( void );
	void equip(AWeapon* weapon);
	void attack(Enemy* enemy);
	std::string const & getName( void ) const;
	int getActionPoints( void ) const;
	AWeapon* getWeapon( void ) const;


private:
	std::string _name;
	int 		_ap;
	AWeapon*	_weapon;

	Character( void );

};

std::ostream & operator<<(std::ostream & out, Character const & character);

#endif