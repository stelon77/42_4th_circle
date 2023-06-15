/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:52:12 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/03 16:24:57 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <iostream>
#include <sstream>
#include <string>

class Human
{
public:
	Human();
	~Human();

	Brain const & getBrain(void) const;
	std::string identify(void);

private:
	Brain const _brain;
};

#endif