/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:56:48 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/07 23:16:37 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & other ){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & other ){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return ( _fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	_fixedPointValue = raw;
}
