/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:50:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/24 18:10:13 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(0));
	Intern glaireux;
	Form* form;
	Bureaucrat a("The King", 1);

	try
	{
		form = glaireux.makeForm("presidential pardon", "Trump");
		std::cout << *form;
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n";
	try
	{
		form = glaireux.makeForm("robotomy request", "R2D2");
		std::cout << *form;
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n";
	try
	{
		form = glaireux.makeForm("shrubbery creation", "home");
		std::cout << *form;
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n";
	try
	{
		form = glaireux.makeForm("the ultimate form", "Trump");
		std::cout << *form;
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}