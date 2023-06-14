#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>


class Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		createContact(void);
		void		displayShortContact(int index) const;
		void		displayFullContact(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getLogin(void) const;
		std::string	getPostalAddress(void) const;
		std::string	getEmailaddress(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getBirthdayDate(void)const;
		std::string	getFavoriteMeal(void) const;
		std::string	getUnderwearColor(void) const;
		std::string	getDarkestSecret(void) const;

		static int	getNbContact(void);

	private:

		std::string _adaptLength(std::string entry) const;

		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _login;
		std::string _postalAddress;
		std::string _emailAddress;
		std::string _phoneNumber;
		std::string _birthdayDate;
		std::string _favoriteMeal;
		std::string _underwearColor;
		std::string _darkestSecret;

		static int	_nbContact;
};

int					chooseContact(int contactNb);


#endif