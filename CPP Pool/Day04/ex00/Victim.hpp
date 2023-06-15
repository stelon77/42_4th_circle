/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 07:21:41 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 23:02:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include  <string>
#include <iostream>

class Victim
{
public:
	Victim( std::string name );
	Victim( Victim const & other);
	Victim & operator=(Victim const & other);
	virtual ~Victim( void );

	std::string	getName( void ) const;
	virtual void getPolymorphed( void ) const;

protected:
	std::string _name;
	Victim( void );

};

std::ostream & operator<<(std::ostream & out, Victim const & s);

#endif