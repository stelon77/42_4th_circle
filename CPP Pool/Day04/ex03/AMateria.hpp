/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 14:34:52 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
public:

	AMateria(std::string const & type);
	AMateria( AMateria const & other);
	virtual ~AMateria();

	AMateria & operator=(AMateria const & other);

	std::string const & getType(void) const;
	unsigned int getXP(void) const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string _type;

private:
	AMateria( void );

	unsigned int _xp;
};

#endif