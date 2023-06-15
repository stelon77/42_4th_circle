/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:24:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 18:00:42 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>
#include <string>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator( void );
	AssaultTerminator( AssaultTerminator const & other);
	virtual ~AssaultTerminator( void );

	AssaultTerminator & operator=(AssaultTerminator const & other);

	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;


private:

};


#endif