/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:39:01 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
# define FIRE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>

class Fire : public AMateria
{
public:
	Fire( void );
	Fire( Fire const & other);
	virtual ~Fire( void );

	Fire & operator=(Fire const & other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

private:

};


#endif