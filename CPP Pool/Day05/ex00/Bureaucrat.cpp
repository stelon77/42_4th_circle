/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ){}

Bureaucrat::Bureaucrat( std::string name, int grade ) :
_name(name)
{
	try
	{
		if (grade < 1)
		{
			_grade = 1;
			throw(Bureaucrat::GradeTooHighException());
		}
		if (grade > 150)
		{
			_grade = 150;
			throw(Bureaucrat::GradeTooLowException());
		}
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat::Bureaucrat( Bureaucrat const & other){
	*this = other;
	return;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other){
	if (this != &other)
		_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName( void ) const{
	return (_name);
}
int Bureaucrat::getGrade( void ) const{
	return (_grade);
}

void Bureaucrat::incrementGrade( void ){
	try
	{
		if (_grade - 1 < 1)
			throw(Bureaucrat::GradeTooHighException());
		_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void Bureaucrat::decrementGrade( void ){
	try
	{
		if (_grade + 1 > 150)
			throw(Bureaucrat::GradeTooLowException());
		_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("The grade is too low");
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b){
	return (out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl);
}
