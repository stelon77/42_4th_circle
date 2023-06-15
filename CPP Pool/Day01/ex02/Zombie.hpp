/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:39:11 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 11:49:25 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string const type, std::string const name);
	~Zombie();

	void	announce(void) const;

private:

	std::string _type;
	std::string	_name;
};

#endif