/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:50:28 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/24 15:15:06 by lcoiffie         ###   ########.fr       */
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

int main()
{
	srand(time(0));
	Bureaucrat toutpetit("toutpetit", 150);
	Bureaucrat petit("petit", 138);
	Bureaucrat moyen("moyen", 46);
	Bureaucrat haut("haut", 3);

	RobotomyRequestForm robo("robocouic");
	ShrubberyCreationForm shru("maison");
	PresidentialPardonForm pre("Trump");

	std::cout << toutpetit << petit << moyen << haut;
	std::cout << robo << shru << pre;
	toutpetit.signForm(shru);
	toutpetit.executeForm(shru);
	petit.executeForm(shru);
	petit.signForm(shru);
	toutpetit.executeForm(shru);
	petit.executeForm(shru);
	moyen.signForm(robo);
	std::cout << moyen;
	moyen.executeForm(robo);
	moyen.incrementGrade();
	std::cout << moyen;
	moyen.executeForm(robo);
	moyen.executeForm(robo);
	moyen.executeForm(robo);
	haut.signForm(pre);
	haut.executeForm(pre);

	return (0);
}