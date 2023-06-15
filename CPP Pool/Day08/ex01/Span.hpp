/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 23:58:30 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/07 23:58:32 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

class Span
{
public:
	Span( const unsigned int N );
	Span( Span const & other);
	~Span( void );

	Span & operator=(Span const & other);

	void addNumber(const int nbr);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void) const;

	void addRandomQuickly(const unsigned int I);
	void display( void );

private:
	unsigned int _N;
	std::vector<int> _arrayOfInts;

	Span( void );
};


class RandomInt
{
public:
	RandomInt( void );
	RandomInt( RandomInt const & other);
	RandomInt & operator=(RandomInt const & other);
	~RandomInt( void );
	int operator()(void);

private:

};

#endif