/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:12:12 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/29 09:05:50 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "this programm needs ONE argument" << std::endl;
		return (0);
	}

	Conversion s(argv[1]);
	
	s.makeConversion();
	return (0);
}