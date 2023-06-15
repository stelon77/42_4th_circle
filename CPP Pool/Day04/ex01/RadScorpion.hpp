/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:39:01 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"
#include <string>
#include <iostream>

class RadScorpion : public Enemy
{
public:
	RadScorpion( void );
	RadScorpion( RadScorpion const & other);
	RadScorpion & operator=(RadScorpion const & other);
	virtual ~RadScorpion( void );

private:

};

#endif