/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:21:58 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:19:37 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include <string>
#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap( void );
	SuperTrap( std::string const name );

	SuperTrap( SuperTrap const & other);
	SuperTrap & operator=( SuperTrap const & other );
	~SuperTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	// void	afficher();


protected:

};

#endif