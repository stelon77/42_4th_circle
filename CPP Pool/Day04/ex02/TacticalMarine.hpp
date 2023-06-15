/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:23:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/17 15:51:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine( TacticalMarine const & other);
	virtual ~TacticalMarine();

	TacticalMarine & operator=(TacticalMarine const & other);

	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;

private:

};


#endif