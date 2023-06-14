/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:38:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/01 15:19:17 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

int Contact::_nbContact = 0;

Contact::Contact(){
}

Contact::~Contact(){
	Contact::_nbContact--;
}

int Contact::getNbContact(void){
	return Contact::_nbContact;
}

std::string Contact::getFirstName(void) const{
	return (_firstName);
}

std::string Contact::getLastName(void) const{
	return (_lastName);
}

std::string Contact::getNickname(void) const{
	return (_nickname);
}

std::string Contact::getLogin(void) const{
	return (_login);
}

std::string Contact::getPostalAddress(void) const{
	return (_postalAddress);
}

std::string Contact::getEmailaddress(void) const{
	return (_emailAddress);
}

std::string Contact::getPhoneNumber(void) const{
	return (_phoneNumber);
}

std::string Contact::getBirthdayDate(void) const{
	return (_birthdayDate);
}

std::string Contact::getFavoriteMeal(void) const{
	return (_favoriteMeal);
}

std::string Contact::getUnderwearColor(void) const{
	return (_underwearColor);
}

std::string Contact::getDarkestSecret(void) const{
	return (_darkestSecret);
}

void Contact::createContact(void){
	Contact::_nbContact++;
	std::cout << "NEW CONTACT" << std::endl;
	std::cout << "Enter contact first name : ";
	std::getline(std::cin, _firstName);
	std::cout << "Enter contact last name : ";
	std::getline(std::cin, _lastName);
	std::cout << "Enter contact nickname : ";
	std::getline(std::cin, _nickname);
	std::cout << "Enter contact login : ";
	std::getline(std::cin, _login);
	std::cout << "Enter contact postal address : ";
	std::getline(std::cin, _postalAddress);
	std::cout << "Enter contact email address : ";
	std::getline(std::cin, _emailAddress);
	std::cout << "Enter contact phone number : ";
	std::getline(std::cin, _phoneNumber);
	std::cout << "Enter contact birthday date : ";
	std::getline(std::cin, _birthdayDate);
	std::cout << "Enter contact favorite meal : ";
	std::getline(std::cin, _favoriteMeal);
	std::cout << "Enter contact underwear color : ";
	std::getline(std::cin, _underwearColor);
	std::cout << "Enter contact darkest secret : ";
	std::getline(std::cin, _darkestSecret);
	return ;
}

void Contact::displayShortContact(int index) const{
	std::cout << std::setw(10);
	std::cout << (index + 1) << "|";
	std::cout << std::setw(10);
	std::cout << _adaptLength(_firstName) << "|";
	std::cout << std::setw(10);
	std::cout << _adaptLength(_lastName) << "|";
	std::cout << std::setw(10);
	std::cout << _adaptLength(_nickname) << std::endl;
}

void Contact::displayFullContact() const{
	std::cout << "First name : " << _firstName << std::endl;
	std::cout << "Last name : " << _lastName << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Login : " << _login << std::endl;
	std::cout << "Postal address : " << _postalAddress << std::endl;
	std::cout << "Email address : " << _emailAddress << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Birthday date : " << _birthdayDate << std::endl;
	std::cout << "Favorite meal : " << _favoriteMeal << std::endl;
	std::cout << "Underwear color : " << _underwearColor << std::endl;
	std::cout << "Darkest secret : " << _darkestSecret << std::endl;
}

std::string Contact::_adaptLength(std::string entry) const
{
	std::string ret;

	ret = entry;
	if (ret.size() < 11)
		return ret;
	else
		ret = entry.substr(0, 9) + ".";
	return (ret);
}

int		chooseContact(int contactNb)
{
	std::string	str;
	int			ret(0);

	while (true)
	{
		std::cout << "which contact do you want (index number) ? ";
		std::getline(std::cin, str);
		if (isdigit(str[0]) && str.size() < 2)
		{
			ret = std::stoi(str,nullptr, 10);
			if (ret > 0 && ret <= contactNb)
				return (ret);
			else if (contactNb == 1)
				std::cout << "index number should be 1" << std::endl;
			else
				std::cout << "index number should be between 1 and " << contactNb << std::endl;
		}
		else
			std::cout << "wrong imput" << std::endl;
	}
}


