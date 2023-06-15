/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:18:07 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string const name );

	FragTrap( FragTrap const & other);
	FragTrap & operator=( FragTrap const & other );
	~FragTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	vaulthunter_dot_exe(std::string const & target);
	// void 	afficher();

protected:
	static std::string _attackShout[5];
};

#endif