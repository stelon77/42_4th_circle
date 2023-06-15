/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alien.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:24:50 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 22:48:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Victim.hpp"

class Alien : public Victim
{
public:
	Alien( std::string name );
	Alien( Alien const & other);
	Alien & operator=(Alien const & other);
	virtual ~Alien( void );

	virtual void getPolymorphed( void ) const;

private:
	Alien (void);


};

#endif