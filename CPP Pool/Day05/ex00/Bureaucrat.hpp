/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:16 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/20 20:42:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & other);
	virtual ~Bureaucrat( void );

	Bureaucrat & operator=(Bureaucrat const & other);

	std::string getName( void ) const;
	int getGrade( void ) const;
	void incrementGrade( void );
	void decrementGrade( void );

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};

protected:
	std::string const _name;
	int _grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b);

#endif