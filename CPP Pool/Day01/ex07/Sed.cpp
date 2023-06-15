/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:28:54 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 15:03:28 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string const filename, std::string const s1, std::string const s2):
	_filename(filename), _s1(s1), _s2(s2)
{
}

Sed::~Sed()
{
}

void Sed::replace(void){
	if (_filename.empty() || _s1.empty() || _s2.empty())
	{
		std::cout << "at least one of your arguments is empty" << std::endl;
		return;
	}
	if (!_createString())
		return;
	_filename = _createNewFileName();
	_str = _manipulateString(_str);
	if (!_createNewFile())
		return;
}

bool Sed::_createString(void){
	char c;
	std::ifstream ifs (_filename.c_str(), std::ifstream::in);
	
	if (!ifs)
	{
		std::cout << "input file opening error" << std::endl;
		return (false);
	}
	c = ifs.get();
	while (ifs.good())
	{
		_str += c;
		c = ifs.get();
	}
	return (true);
}

std::string Sed::_manipulateString(std::string str){
	std::size_t found = 0;

	while  (found!=std::string::npos)
	{
		found = str.find(_s1, found);
		if (found!=std::string::npos)
		{
			str.replace(found, _s1.size(), _s2);
			found += _s2.size();
		}
	}
	return (str);
}

bool		Sed::_createNewFile(void) const{
	std::ofstream out(_filename.c_str());
	if (!out)
	{
		std::cout << "output file opening error" << std::endl;
		return (false);
	}
	out << _str;
	return (true);
}


std::string		Sed::_createNewFileName(void) const{
	std::string name;

	for (unsigned long i = 0; i < _filename.size(); i++)
		name += (char)std::toupper(_filename[i]);
	name += ".replace";
	return (name);
}
