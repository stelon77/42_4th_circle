/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:55:05 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/07 23:50:53 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

void display(int n){
	std::cout << n << " ";
}

int main()
{
	srand(time(0));
	std::cout << "exemple de main\n";
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "exemple de petit N\n";
	Span a(6);
	a.addNumber(2);
	a.addNumber(42);
	a.addRandomQuickly(4);
	a.display();
	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;

	std::cout << "revue des exceptions\n";
	std::cout << "rajout dans tableau d'un element\n";
	try
	{
		a.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "tableau non rempli\n";

	Span b(15500);
	try
	{
		std::cout << b.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "ou avec un seul element\n";
	b.addNumber(-2147123456);
	try
	{
		std::cout << b.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "et maintenant plein d'int\n";
	b.addRandomQuickly(150000);
	std::cout << "oups je m'etais trompe d'un zero\n";
	b.addRandomQuickly(15499);
	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;

	Span c(1000000);
	std::cout << "\net maintenant un million !\n";
	c.addRandomQuickly(1000000);
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;












	// a.addNumber(-3);
	// a.addNumber(-423);
	// a.addNumber(2436);
	// a.addNumber(560);
	// try
	// {
	// 	a.addNumber(0);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	return (0);
}