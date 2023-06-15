/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 08:57:37 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 09:14:59 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "not the right number of arguments" << std::endl;
		return (0);
	}
	Sed sed(argv[1], argv[2], argv[3]);
	sed.replace();
	return (0);
}