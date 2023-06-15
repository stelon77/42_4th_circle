cd /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:24:50 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 22:48:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon( std::string name );
	Peon( Peon const & other);
	Peon & operator=(Peon const & other);
	virtual ~Peon( void );

	virtual void getPolymorphed( void ) const;

private:
	Peon (void);


};

#endif