/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:16:56 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:17:36 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string const name );
	ClapTrap( std::string const name, int hp, int maxhp, int ep, int maxep, int lvl, int mad, int rad, int adr);

	ClapTrap( ClapTrap const & other);
	ClapTrap & operator=( ClapTrap const & other );
	~ClapTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	// void 	afficher();

protected:
	int	_hitPoints;
	int	_maxHitPoints;
	int	_energyPoints;
	int	_maxEnergyPoints;
	int	_level;
	int	_meleeAttackDamage;
	int	_rangedAttackDamage;
	int	_armorDamageReduction;
	std::string	_name;

};

#endif