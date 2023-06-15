/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 21:34:35 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/02 21:49:10 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*pointer;
	std::string &reference = str;

	pointer = &str;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;
	return (0);
}