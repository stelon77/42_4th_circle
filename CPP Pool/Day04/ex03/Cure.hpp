/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 17:47:30 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( Cure const & other);
	virtual ~Cure( void );

	Cure & operator=(Cure const & other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

private:

};


#endif