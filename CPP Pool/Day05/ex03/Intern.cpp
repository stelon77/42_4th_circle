/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	_forms[0] = "shrubbery creation";
	_forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";
	_make[0] = makeSC;
	_make[1] = makeRR;
	_make[2] = makePP;
}

Intern::~Intern( void )
{
}

Intern::Intern( Intern const & other){
	*this = other;
	return;
}


Intern & Intern::operator=(Intern const & other){
	(void) other;
    return *this;
}

Form* Intern::makeForm(std::string const & name, std::string const & target) const{
		for (int i = 0; i < 3; i++)
		{
			if (name == _forms[i])
			{
				std::cout << "Intern creates " << name << " form" << std::endl;
				return (_make[i](target));
			}
		}
		throw(Intern::NotAKnownFormException());
		return (0);
}

Form* Intern::makeSC(std::string const & target){
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRR(std::string const & target){
	return (new RobotomyRequestForm(target));
}

Form* Intern::makePP(std::string const & target){
	return (new PresidentialPardonForm(target));
}

const char* Intern::NotAKnownFormException::what() const throw(){
	return ("Euh...Sorry I'm a slug...I can't find the form you asked...");
}
