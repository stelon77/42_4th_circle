/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:56:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/07 23:00:42 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		Fixed( Fixed const & other );
		~Fixed( void );

		Fixed & operator=( Fixed const & other );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

private:
		int 				_fixedPointValue;
		static const int	_bits = 8;
};

std::ostream & operator<<( std::ostream & flux, Fixed const & i );

#endif