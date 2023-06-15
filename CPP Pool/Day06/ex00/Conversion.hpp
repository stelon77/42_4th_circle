/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <limits>


class Conversion
{
public:
	Conversion( std::string str );
	Conversion( Conversion const & other);
	Conversion & operator=(Conversion const & other);
	virtual ~Conversion( void );

	bool	checkSpecialStr(void);
	bool	checkZero(void);
	bool	checkNumber(void);
	void	makeConversion (void);

	void toChar( void ) const;
	void toInt( void ) const;
	void toFloat( void ) const;
	void toDouble( void ) const;
	void display( void ) const;


private:
	std::string _stringToConvert;
	double _doubleToConvert;

	Conversion( void );
};


#endif