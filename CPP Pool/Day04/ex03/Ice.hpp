/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:39:01 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( Ice const & other);
	virtual ~Ice( void );

	Ice & operator=(Ice const & other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

private:

};


#endif