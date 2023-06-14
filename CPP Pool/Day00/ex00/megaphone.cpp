/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:05:34 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/12/25 20:33:24 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int main(int argc, char *argv[])
{
	std::string str("");
	int			count;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (count = 1; count < argc; count++)
			str += argv[count];
		count = -1;
		while (str[++count])
			std::cout << (char)std::toupper(str[count]);
		std::cout << std::endl;
	}
	return (0);
}