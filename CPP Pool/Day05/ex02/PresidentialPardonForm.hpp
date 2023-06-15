/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & other);
	virtual ~PresidentialPardonForm( void );

	PresidentialPardonForm & operator=(PresidentialPardonForm const & other);
	virtual bool execute(Bureaucrat const & executor) const;
	virtual void execution(void) const;

protected:
	std::string _target;

private:
	PresidentialPardonForm( void );


};


#endif