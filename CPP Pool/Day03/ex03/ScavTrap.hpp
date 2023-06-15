/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 11:56:04 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string const name );

	ScavTrap( ScavTrap const & other);
	ScavTrap & operator=( ScavTrap const & other );
	~ScavTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	challengeNewcomer(std::string const & target) const;

protected:
	static std::string _challenges[5];
};

#endif