/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:24:00 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/17 20:23:59 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
public:
	Squad( void );
	Squad( Squad const & other);
	virtual ~Squad( void );

	Squad & operator=(Squad const & other);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int nb) const;
	virtual int push(ISpaceMarine* soldier);

protected:
	int	_count;
	ISpaceMarine** _unit;
};


#endif