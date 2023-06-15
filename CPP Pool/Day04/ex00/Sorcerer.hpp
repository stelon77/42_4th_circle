/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:18:46 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 23:02:34 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORCERER_HPP
# define SORCERER_HPP

#include  <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer( std::string name, std::string title );
	Sorcerer( Sorcerer const & other);
	Sorcerer & operator=(Sorcerer const & other);
	~Sorcerer( void );

	std::string	getName( void ) const;
	std::string	getTitle ( void ) const;

	void polymorph( Victim const & victim) const;

protected:
	std::string _name;
	std::string _title;

private:
	Sorcerer( void );
};

std::ostream & operator<<(std::ostream & out, Sorcerer const & s);

#endif