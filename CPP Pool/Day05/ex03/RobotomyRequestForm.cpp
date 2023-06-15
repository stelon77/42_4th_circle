/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ){}

RobotomyRequestForm::RobotomyRequestForm( std::string target):
Form("robotomy request", 72, 45), _target(target){}


RobotomyRequestForm::~RobotomyRequestForm( void ){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & other){
	*this = other;
	return;
}


RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other){
	if (this != &other)
	{
		Form::operator=(other);
		_target = other._target;
	}
    return *this;
}

void RobotomyRequestForm::execution(void) const{
	std::cout << "wwwwiiIiIIIIIIIIIZZZZZZZZZZZZ........wwwwiiIiIIIIIIIIIZZZZZZZZZZZZ" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failure..." << std::endl;
	return ;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (Form::execute(executor))
	{
		execution();
		return(true);
	}
	return (false);
}