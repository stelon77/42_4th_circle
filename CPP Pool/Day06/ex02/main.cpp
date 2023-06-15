/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:41:17 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/07 21:27:01 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base { public: virtual ~Base(){}};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void){
	int i = rand() % 3;
	if (!i)
	{
		std::cout << "\nclass A is YOUR class...\n\n";
		return (new A);
	}
	if (i == 1)
	{
		std::cout << "\nMy name is B, class B\n\n";
		return (new B);
	}
	std::cout << "\nC is THE chosen one\n\n";
	return (new C);
}

void identify_from_pointer(Base * p){
	std::cout << "The winner from pointer is : ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "none of the three" << std::endl;
}

void identify_from_reference( Base & p){
	Base base;

	std::cout << "and from reference is : ";
	try
	{
		base = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		base = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		base = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}

}

int main()
{
	srand(time(0));

	Base* inst1 = generate();
	identify_from_pointer(inst1);
	identify_from_reference(*inst1);
	delete inst1;

	return (0);
}