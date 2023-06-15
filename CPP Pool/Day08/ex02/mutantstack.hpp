/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 23:59:14 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/08 11:23:16 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>


template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack( void ) : std::stack<T>(){}
	MutantStack( MutantStack const & other) : std::stack<T>(other) {}
	~MutantStack( void ) {}

	MutantStack & operator=(MutantStack const & other){
		std::stack<T>::operator=(other);
		return *this;}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin( void) {return std::stack<T>::c.begin();}
	iterator end(void) {return std::stack<T>::c.end();}

};

#endif
