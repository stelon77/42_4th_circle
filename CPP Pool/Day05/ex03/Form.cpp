/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:22:47 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/24 14:43:39 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ):_signed(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form( std::string name, int const sign, int const execute) :
_name(name),_signed(false), _gradeToSign(sign), _gradeToExecute(execute){
	try
	{
		if (sign < 1 || execute < 1)
			throw(Form::GradeTooHighException());
		if (sign > 150 || execute > 150)
			throw(Form::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::~Form( void ) {}

Form::Form( Form const & other) :
_name(other._name),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute)
{
	*this = other;
	return;
}

Form & Form::operator=(Form const & other){
	if (this != &other)
		_signed = other._signed;
    return *this;
}

std::string Form::getName( void ) const{
	return (_name);
}

int Form::getGradeToSign( void ) const{
	return (_gradeToSign);
}

int Form::getGradeToExecute( void ) const{
	return (_gradeToExecute);
}

bool Form::getSigned( void ) const{
	return (_signed);
}

void Form::beSigned(Bureaucrat const & johndoe){
	try
	{
		if (johndoe.getGrade() > _gradeToSign)
			throw(Form::GradeTooLowException());
		_signed = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

bool Form::execute(Bureaucrat const & executor) const{
	if (!_signed)
	{
		std::cout << executor.getName() << " cannot execute "<< getName() << " because it's not signed\n";
		return (false);
	}
	try
	{
		if (executor.getGrade() > _gradeToExecute)
			throw(Form::GradeTooLowException());
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << executor.getName() << " cannot execute "<< getName() << " because his grade is too low\n";

	}
	return (false);
}


const char* Form::GradeTooHighException::what() const throw(){
	return ("Form :the grade is too high");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Form : the grade is too low");
}

std::ostream & operator<<(std::ostream & out, Form const & f){
	out << "form " << f.getName() << ", grade " << f.getGradeToSign();
	out << " necessary to sign it, and grade " << f.getGradeToExecute();
	out << " necessary to execute it, ";
	if (f.getSigned())
		out << "has been signed" << std::endl;
	else
		out << "is yet unsigned" << std::endl;
	return (out);
}
