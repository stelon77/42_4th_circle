/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/08 10:54:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ){}

PresidentialPardonForm::PresidentialPardonForm( std::string target ):
Form("presidential pardon", 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & other){
	*this = other;
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other){
	if (this != &other)
	{
		Form::operator=(other);
		_target = other._target;
	}
    return *this;
}

void PresidentialPardonForm::execution(void) const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (Form::execute(executor))
	{
		execution();
		return(true);
	}
	return (false);
}
