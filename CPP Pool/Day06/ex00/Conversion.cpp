/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion( void ){}

Conversion::Conversion( std::string str ):
_stringToConvert(str)
{}

Conversion::~Conversion( void ){}

Conversion::Conversion( Conversion const & other){
	*this = other;
	return;
}

Conversion & Conversion::operator=(Conversion const & other){
	if (this != &other)
	{
		_stringToConvert = other._stringToConvert;
		_doubleToConvert = other._doubleToConvert;
	}
    return *this;
}

bool	Conversion::checkSpecialStr(void){
	if (_stringToConvert == "nan" || _stringToConvert == "nanf")
		_doubleToConvert = NAN;
	else if (_stringToConvert == "+inff" || _stringToConvert == "+inf")
		_doubleToConvert = INFINITY;
	else if (_stringToConvert == "-inff" || _stringToConvert == "-inf")
		_doubleToConvert = -INFINITY;
	else if (_stringToConvert.size() == 1)
	{
		if (_stringToConvert[0] >47 && _stringToConvert[0] < 58)
			_doubleToConvert = std::atof(_stringToConvert.c_str());
		else
			_doubleToConvert = _stringToConvert[0];
	}
	else
		return (false);
	return (true);
}

bool Conversion::checkZero(void){
	int i = 0;

	_doubleToConvert = 0.0;
	while (_stringToConvert[i])
	{
		while (std::isspace( _stringToConvert[i]))
			i++;
		if (_stringToConvert[i] == '+' || _stringToConvert[i] == '-')
			i++;
		while (_stringToConvert[i] == '0')
			i++;
		if (_stringToConvert[i] == '.')
			i++;
 		if (_stringToConvert[i] == 'f' && _stringToConvert[i + 1])
			return (0);
		while (_stringToConvert[i] == '0')
			i++;
		if (_stringToConvert[i] == 'f' && !_stringToConvert[i + 1])
			return (true);
		if  (_stringToConvert[i])
			return (false);
	}
	return (true);
}

bool Conversion::checkNumber(void){
	char* retour = NULL;
	double conv;

	conv = std::strtod(_stringToConvert.c_str(), &retour);
	if (!conv)
		return (false);
	if (retour[0] == 0 || (retour[0]== 'f' && retour[1] == 0))
	{
		_doubleToConvert = conv;
		return (true);
	}
	return (false);
}

void Conversion::makeConversion (void){
	if (checkSpecialStr() || checkZero() || checkNumber())
		display();
	else
		std::cout << "argument not valid" << std::endl;
	return;
}

void Conversion::toChar( void ) const {
	std::cout << "char : ";
	if (_doubleToConvert < -128.0 || _doubleToConvert > 127.0 || !isfinite(_doubleToConvert))
		std::cout << "impossible" << std::endl;
	else if (_doubleToConvert < 32.0 || _doubleToConvert > 126.0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast< char >(_doubleToConvert) << "'" <<std::endl;
}

void Conversion::toInt( void ) const {
	std::cout << "int : ";
	if (_doubleToConvert < std::numeric_limits<int>::min() || _doubleToConvert > std::numeric_limits<int>::max() || !isfinite(_doubleToConvert))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(_doubleToConvert) << std::endl;
}

void Conversion::toFloat( void ) const{
	std::cout << "float : ";
	if ((_doubleToConvert < -3.402823466385288598e+38 || _doubleToConvert > 3.402823466385288598e+38)
		&& isfinite(_doubleToConvert))
	{
			std::cout << "impossible" << std::endl;
			return ;
	}
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_doubleToConvert) << "f" << std::endl;
}

void Conversion::toDouble( void ) const{
	std::cout << "double : " << std::fixed << std::setprecision(1) << _doubleToConvert << std::endl;
}

void Conversion::display( void ) const{
	toChar();
	toInt();
	toFloat();
	toDouble();
}