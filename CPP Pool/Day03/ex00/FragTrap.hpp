/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 10:45:29 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class FragTrap
{
public:
	FragTrap( void );
	FragTrap( std::string const name );

	FragTrap( FragTrap const & other);
	FragTrap & operator=( FragTrap const & other );
	~FragTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

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

	static std::string _attackShout[5];
};

#endif