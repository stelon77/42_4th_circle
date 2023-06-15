/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 10:48:10 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ScavTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string const name );

	ScavTrap( ScavTrap const & other);
	ScavTrap & operator=( ScavTrap const & other );
	~ScavTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & target) const;

private:
	int	_hitPoints;
	int	_maxHitPoints;
	int	_energyPoints;
	int	_maxEnergyPoints;
	int	_level;
	int	_meleeAttackDamage;
	int	_rangedAttackDamage;
	int	_armorDamageReduction;
	std::string	_name;

	static std::string _challenges[5];
};

#endif