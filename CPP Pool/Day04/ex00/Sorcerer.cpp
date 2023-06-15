/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:19:08 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/15 11:04:28 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void )
{
}

Sorcerer::Sorcerer( std::string name, std::string title ):
	_name(name),
	_title(title)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer( void )
{
	std::cout << _name << ", " << _title <<" , is dead. Consequences will never be the same!" << std::endl;
}


Sorcerer::Sorcerer( Sorcerer const & other){
	*this = other;
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
	return;
}


Sorcerer & Sorcerer::operator=(Sorcerer const & other){
	if (this != &other)
	{
		_name = other._name;
		_title = other._title;
    }
    return *this;
}

std::string Sorcerer::getName( void ) const{
	return _name;
}

std::string Sorcerer::getTitle ( void ) const{
	return _title;
}

void Sorcerer::polymorph(Victim const & victim) const{
	victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & out, Sorcerer const & s){
	return (out << "I am " << s.getName() << ", " << s.getTitle() << " and I like ponies!" << std::endl);
}
