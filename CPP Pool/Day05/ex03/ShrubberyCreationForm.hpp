/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & other);
	virtual ~ShrubberyCreationForm( void );

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);

	virtual bool execute(Bureaucrat const & executor) const;
	virtual void execution(void) const;

protected:
	std::string _target;

private:
	ShrubberyCreationForm( void );

};


#endif