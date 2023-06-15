/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
Form("shrubbery creation", 145, 137), _target(target){}


ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other){
	*this = other;
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other){
	if (this != &other)
	{
		Form::operator=(other);
		_target = other._target;
	}
    return *this;
}

void ShrubberyCreationForm::execution(void) const{
	std::string fname;

	fname = _target + "_shrubbery";
	try
	{
		std::ofstream out(fname.c_str());
		if (!out)
			throw std::exception();
		out << "\\|// \\\\|/  \\|// \\\\|/" << std::endl;
		out << " \\/   \\/    \\/   \\/" << std::endl;
		out << "  \\  /       \\   /" << std::endl;
		out << "   ||         | |" << std::endl;
		out << "   ||         | |"<< std::endl;
		out << "   ||         | |" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (Form::execute(executor))
	{
		execution();
		return(true);
	}
	return (false);
}