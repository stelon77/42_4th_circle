/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern( Intern const & other);
	virtual ~Intern( void );

	Intern & operator=(Intern const & other);

	Form* makeForm(std::string const & name, std::string const & target)const;

	class NotAKnownFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	static Form* makeSC(std::string const & target);
	static Form* makeRR(std::string const & target);
	static Form* makePP(std::string const & target);

	std::string _forms[3];
	Form* (*_make[3])(std::string const & target);
};


#endif