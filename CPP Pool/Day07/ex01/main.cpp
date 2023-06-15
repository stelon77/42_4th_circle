/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:01:46 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/02 22:51:30 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
	char tab[6] = {'a','b','c','d','e','f'};
	std::cout << "\n\ninitial tab\n";
	iter(tab, 6, display);
	std::cout << "\nincremented tab\n";
	iter(tab, 6, increment);
	iter(tab, 6, display);

	double tab2[6] = {1.3, 3, 3.14, 1.414, 1.732, 12e3 };
	std::cout << "\n\ninitial tab\n";
	iter(tab2, 6, display);
	std::cout << "\nincremented tab\n";
	iter(tab2, 6, increment);
	iter(tab2, 6, display);

	char cesar[] = "YouAreAWinner";
	iter(cesar,std::char_traits<char>::length(cesar) , decrement);
	std::cout << "\n\nThis is a Cesar code :\n";
	iter(cesar, std::char_traits<char>::length(cesar), display);
	std::cout << "\nand the translation is :\n";
	iter(cesar, std::char_traits<char>::length(cesar), increment);
	iter(cesar, std::char_traits<char>::length(cesar), display);
	std::cout << std::endl;
	return (0);
}

