/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:56:39 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/07 23:17:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
		Fixed( void );
		Fixed( Fixed const & other );
		~Fixed( void );

		Fixed &	operator=(Fixed const & other);

		int		getRawBits( void ) const;
		void	setRawBits(int const raw);

private:
		int					_fixedPointValue;
		static const int	_bits = 8;
};

#endif