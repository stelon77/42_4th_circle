/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:19:52 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/12/28 16:12:27 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

int main()
{
	Contact			contact[8];
	bool			keeprunning(true);
	std::string		instruction;
	int				nb;

	while(keeprunning)
	{
		std::cout << "What do you want to do (ADD, SEARCH or EXIT)? : ";
		std::getline(std::cin, instruction);
		if (instruction == "EXIT")
			keeprunning = false;
		else if (instruction == "ADD")
		{
			if (Contact::getNbContact() < 8)
				contact[Contact::getNbContact()].createContact();
			else
				std::cout << "The phonebook is full, SEARCH or EXIT only !!" << std::endl;
		}
		else if (instruction == "SEARCH")
		{
			if (Contact::getNbContact() == 0)
				std::cout << "you don't have any contact, ADD some contact first" << std::endl;
			else
			{
				std::cout << "     index|first name| last name|  nickname" << std::endl;
				std::cout << "----------|----------|----------|----------" << std::endl;
				for (int i = 0; i < Contact::getNbContact(); i++)
					contact[i].displayShortContact(i);
				nb = chooseContact(Contact::getNbContact());
				contact[nb - 1].displayFullContact();
			}
		}
		else
			std::cout << "instructions are ADD, SEARCH or EXIT only, please try again..." << std::endl;
	}
	return (0);
}