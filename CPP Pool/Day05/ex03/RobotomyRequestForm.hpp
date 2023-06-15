/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm( std::string target);
	RobotomyRequestForm( RobotomyRequestForm const & other);
	virtual ~RobotomyRequestForm( void );

	RobotomyRequestForm & operator=(RobotomyRequestForm const & other);

	virtual bool execute(Bureaucrat const & executor) const;
	virtual void execution(void) const;

protected:
	std::string _target;

private:
	RobotomyRequestForm( void );

};


#endif