/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 23:58:04 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/07 23:58:05 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span(void){}

Span::Span( const unsigned int N ):
_N(N)
{}

Span::~Span( void )
{
}

Span::Span( Span const & other){
	*this = other;
	return;
}


Span & Span::operator=(Span const & other){
	if (this != &other)
	{
		_arrayOfInts = other._arrayOfInts;
		_N = other._N;
	}
    return *this;
}

void Span::addNumber(const int nb){
	if (_arrayOfInts.size() == _N)
		throw(std::exception());
	_arrayOfInts.push_back(nb);
}

unsigned int Span::longestSpan(void) const{
	if (_arrayOfInts.size() <= 1)
		throw(std::exception());
	return (*std::max_element(_arrayOfInts.begin(), _arrayOfInts.end())
				- *std::min_element(_arrayOfInts.begin(), _arrayOfInts.end()));
}

unsigned int Span::shortestSpan(void){
	unsigned int i;

	if (_arrayOfInts.size() <= 1)
		throw(std::exception());
	std::sort(_arrayOfInts.begin(), _arrayOfInts.end());
	i = *(_arrayOfInts.begin() + 1) - *_arrayOfInts.begin();
	for (std::vector<int>::iterator it = _arrayOfInts.begin() + 1; it != _arrayOfInts.end(); ++it)
		if (i > static_cast<unsigned int>(*it - *(it-1)))
			i = static_cast<unsigned int>(*it - *(it - 1));
	return (i);
}

void Span::addRandomQuickly(const unsigned int I){
	int size = _arrayOfInts.size();

	if (_N < I + size)
	{
		std::cout << "I can't create a container larger than " << _N << " integers" << std::endl;
		std::cout << "actual number of integers in container is " << size << std::endl;
		return ;
	}
	_arrayOfInts.resize(size + I);
	std::generate(_arrayOfInts.begin() + size, _arrayOfInts.end(), RandomInt());
}

void Span::display( void ){
	std::cout << "integers : " << std::endl;
	for (std::vector<int>::iterator it = _arrayOfInts.begin(); it != _arrayOfInts.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

RandomInt::RandomInt( void ){}

RandomInt::~RandomInt( void ){}

RandomInt::RandomInt( RandomInt const & other){ *this = other;}

RandomInt & RandomInt::operator=(RandomInt const & other){
	(void) other;
	return *this;
}

int RandomInt::operator()(void){return rand();}
