/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:35:49 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/14 09:18:34 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NINJATRAP_H
# define NINJATRAP_H

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
public:
	NinjaTrap( void );
	NinjaTrap( std::string const name );

	NinjaTrap( NinjaTrap const & other);
	NinjaTrap & operator=( NinjaTrap const & other );
	~NinjaTrap( void );

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	ninjaShoebox(ClapTrap & clap);
	void	ninjaShoebox(FragTrap & frag);
	void	ninjaShoebox(ScavTrap & scav);
	void	ninjaShoebox(NinjaTrap & ninja);
	// void 	afficher();

private:

};

#endif