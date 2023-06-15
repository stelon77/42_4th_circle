/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:44:12 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/03 17:33:12 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	//tableau nul
	std::cout << "tableau nul\n";
	Array<int> a;
	std::cout << "size : " << a.size() << std::endl;
	try
	{
		std::cout << "element 0 : " << a[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//tableau d'int
	std::cout << "\ntableau de 5 int " << std::endl;
	Array<int> b(5);
	std::cout << "size : " << b.size() << std::endl;
	std::cout << "element 0 : " << b[0] << std::endl;
	std::cout << "element 3 : " << b[3] << std::endl;
	std::cout << "\nremplissage du tableau de 5 int " << std::endl;
	for (unsigned int i(0); i < b.size(); i++)
		b[i] = i;
	std::cout << "element 0 : " << b[0] << std::endl;
	std::cout << "element 3 : " << b[3] << std::endl;

	//manipulation de 3 tableaux de string
	Array<std::string> c(4);
	std::cout << "\ntableau de 4 string " << std::endl;
	std::cout << "\nremplissage tableau de 4 string " << std::endl;
	c[0] = "you";
	c[1] = "are";
	c[2] = "a";
	c[3] = "winner";
	std::cout << "\naffichage tableau de 4 string " << std::endl;
	for (unsigned int i(0); i < c.size() ; i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << "\ncopie du tableau " << std::endl;
	Array<std::string> d(c);
	std::cout << "\nchangements elements 0 et 2 " << std::endl;
	d[0] = "we";
	d[2]  ="some";
	std::cout << "\naffichage tableau 1 " << std::endl;
	for (unsigned int i(0); i < c.size() ; i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
	std::cout << "\naffichage tableau 2 " << std::endl;
	for (unsigned int i(0); i < d.size() ; i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	std::cout << "\ntableau(3) de 1 string " << std::endl;
	Array<std::string> f(1);
	try
	{
		std::cout << "element 0 : " << f[0];
		std::cout << "\nelement 1 : " << f[1];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nassignation du tableau 2 au tableau 3 et legers changements " << std::endl;
	f = d;
	f[3] = "losers";
	std::cout << "\naffichage tableau 3" << std::endl;
for (unsigned int i(0); i < f.size() ; i++)
		std::cout << f[i] << " ";
	std::cout << std::endl;




	return (0);
}
