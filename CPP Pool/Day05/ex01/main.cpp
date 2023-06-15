/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:50:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/24 14:18:14 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

int main()
{
	Bureaucrat a("Bob1", 1);
	Bureaucrat b("Bob30", 30);
	Bureaucrat c("Bob150", 150);
	std::cout << a << b << c;
	Form fa("requete", 32, 28);
	Form fb("demande", 3, 1);
	Form fc("impossible", 155, 3);
	Form fd("impossible2", 55, -3);


	c.signForm(fa);
	std::cout << fa;

	b.signForm(fa);
	std::cout << fa;

	a.signForm(fa);
	std::cout << fa;

	b.signForm(fb);
	std::cout << fb;

	a.signForm(fb);
	std::cout << fb;

	return (0);
}