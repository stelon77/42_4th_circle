/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:42:19 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/06 11:50:29 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::list<int> laListe;

	laListe.push_back(1);
	laListe.push_back(1);
	laListe.push_back(2);
	laListe.push_back(1);
	laListe.push_back(3);
	laListe.push_back(4);
	std::list<int>::iterator it;
	try
	{
		it = easyFind(laListe, 3);
		std::cout << *it << std::endl;
		it = easyFind(laListe, 5);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int> leVector(8, 0);
	leVector[0] = (374);
	leVector.push_back(1042);
	leVector.push_back(-456);
	leVector.push_back(896);
	leVector.push_back(0);
	leVector.push_back(36);
	leVector.push_back(42);
	leVector.push_back(-65);

	std::vector<int>::iterator it2;
	it2 = easyFind(leVector, -65);
	std::cout << *it2 << std::endl;
	it2 = easyFind(leVector, 374);
	std::cout << *it2 << std::endl;


	return (0);
}
