/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:25:22 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/17 21:44:36 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

class ISpaceMarine
{
public:
virtual ~ISpaceMarine() {}
virtual ISpaceMarine* clone() const = 0;
virtual void battleCry() const = 0;
virtual void rangedAttack() const = 0;
virtual void meleeAttack() const = 0;
};

#endif