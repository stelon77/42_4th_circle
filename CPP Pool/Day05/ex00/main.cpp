/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:50:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/22 00:01:14 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main()
{
	Bureaucrat a("number 1", 1);
	Bureaucrat b("number 30", 30);
	Bureaucrat c("number 150", 150);
	std::cout << a << b << c;
	//errors of grades
	std::cout << "\ngrades errors \n\n";
	Bureaucrat d("number 153", 151);
	Bureaucrat e("number 0", 0);

	std::cout << d << e;
	std::cout << "\n increment and decrementation \n\n";

	a.decrementGrade();
	b.incrementGrade();
	std::cout << a << b << c;

	std::cout << "\n increment and decrementation errors\n\n";
	a.incrementGrade();
	std::cout << a;
	a.incrementGrade();
	std::cout << a;
	std::cout << c;
	c.decrementGrade();
	std::cout << c;

	return (0);
}