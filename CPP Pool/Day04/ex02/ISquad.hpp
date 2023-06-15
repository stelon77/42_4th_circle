/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:26:41 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/17 21:44:53 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
#define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
public:
virtual ~ISquad() {}
virtual int getCount() const = 0;
virtual ISpaceMarine* getUnit(int) const = 0;
virtual int push(ISpaceMarine*) = 0;
};

#endif