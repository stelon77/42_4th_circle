/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:56:48 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/07 23:16:45 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed() : _fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = n << _bits;
}


Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf( f * ( 1 << _bits));
}

Fixed::Fixed( Fixed const & other ){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & other ){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	return ( _fixedPointValue);
}

void Fixed::setRawBits(int const raw){
	_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const{
	return ((float) _fixedPointValue / (1 << _bits));
}

int Fixed::toInt( void ) const{
	return (_fixedPointValue >> _bits);
}

std::ostream & operator<<( std::ostream & flux, Fixed const & i){
	return ( flux << i.toFloat() );
}
