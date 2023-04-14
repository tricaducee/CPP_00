#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

std::string format::formatString(std::string str, unsigned long length)
{
	if (str.length() > length)
		return str.substr(0, length - 1) + ".";
	return str;
}

using namespace format;

void PhoneBook::addContact()
{
	std::string tmp;
	if (this->_nb_contacts >= MAX_CONTACTS)
		this->_nb_contacts = 0;
	std::cout << "Enter your first name : ";
	std::getline(std::cin, tmp);
	if (std::cin.eof())
			return ;
	this->_contacts[this->_nb_contacts].setFirstName(tmp);
	std::cout << "Enter your last name : ";
	std::getline(std::cin, tmp);
	if (std::cin.eof())
			return ;
	this->_contacts[this->_nb_contacts].setLastName(tmp);
	std::cout << "Enter your nickname : ";
	std::getline(std::cin, tmp);
	if (std::cin.eof())
			return ;
	this->_contacts[this->_nb_contacts].setNickname(tmp);
	std::cout << "Enter your phone number : ";
	std::getline(std::cin, tmp);
	if (std::cin.eof())
			return ;
	this->_contacts[this->_nb_contacts].setPhoneNumber(tmp);
	std::cout << "Enter your darkest secret : ";
	std::getline(std::cin, tmp);
	if (std::cin.eof())
			return ;
	this->_contacts[this->_nb_contacts].setDarkestSecret(tmp);
	this->_nb_contacts++;
}

void PhoneBook::searchContact() const
{
	int	i = 0;
	int n = 0;
	std::cout << "\n---------------------------------------------\n";
	std::cout << "|" << std::left << std::setw(MAX_LENGTH) << formatString("Index", MAX_LENGTH) << "|";
	std::cout << std::setw(MAX_LENGTH) << formatString("First name", MAX_LENGTH) << "|";
	std::cout << std::setw(MAX_LENGTH) << formatString("Last name", MAX_LENGTH) << "|";
	std::cout << std::setw(MAX_LENGTH) << formatString("Nickname", MAX_LENGTH) << "|";
	std::cout << "\n=============================================" << std::endl;
	while (i < MAX_CONTACTS && this->_contacts[i].getFirstName() != "")
	{
		std::cout << "|" << std::right << std::setw(MAX_LENGTH) << i << "|";
		std::cout << std::setw(MAX_LENGTH) << formatString(this->_contacts[i].getFirstName(), MAX_LENGTH) << "|";
		std::cout << std::setw(MAX_LENGTH) << formatString(this->_contacts[i].getLastName(), MAX_LENGTH) << "|";
		std::cout << std::setw(MAX_LENGTH) << formatString(this->_contacts[i].getNickname(), MAX_LENGTH) << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		++i;
	}
	if (!i)
	{
		std::cout << "\nNo contact to display\n" << std::endl;
		return ;
	}
	std::cout << "\nChoose a contact index to display : ";
	while (!(std::cin >> n) || !(n >= 0 && n < i))
	{
		if (std::cin.eof())
			return ;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "\nNot a number or invalid value, please retry : ";
	}
	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(MAX_LENGTH + 5) << formatString("First name", MAX_LENGTH + 5) << ":" << std::right << std::setw(MAX_LENGTH * 3 - 5) << formatString(this->_contacts[n].getFirstName(), MAX_LENGTH * 3 - 5) << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(MAX_LENGTH + 5) << formatString("Last name", MAX_LENGTH + 5) << ":" << std::right << std::setw(MAX_LENGTH * 3 - 5) << formatString(this->_contacts[n].getLastName(), MAX_LENGTH * 3 - 5) << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(MAX_LENGTH + 5) << formatString("Nickname", MAX_LENGTH + 5) << ":" << std::right << std::setw(MAX_LENGTH * 3 - 5) << formatString(this->_contacts[n].getNickname(), MAX_LENGTH * 3 - 5) << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(MAX_LENGTH + 5) << formatString("Phone number", MAX_LENGTH + 5) << ":" << std::right << std::setw(MAX_LENGTH * 3 - 5) << formatString(this->_contacts[n].getPhoneNumber(), MAX_LENGTH * 3 - 5) << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(MAX_LENGTH + 5) << formatString("Darkest secret", MAX_LENGTH + 5) << ":" << std::right << std::setw(MAX_LENGTH * 3 - 5) << formatString(this->_contacts[n].getDarkestSecret(), MAX_LENGTH * 3 - 5) << "|" << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

// void PhoneBook::searchContact(std::string key) const
// {
// 	int	i = 0;
// 	while (i < MAX_CONTACTS)
// 	{
// 		if (key == this->_contacts[i].getFirstName() || key == this->_contacts[i].getLastName() || key == this->_contacts[i].getNickname() || key == this->_contacts[i].getPhoneNumber() || key == this->_contacts[i].getDarkestSecret())
// 		{
// 			std::cout << "Contact index : " << i << std::endl;
// 			std::cout << "First name : " << this->_contacts[i].getFirstName() << std::endl;
// 			std::cout << "Last name : " << this->_contacts[i].getLastName() << std::endl;
// 			std::cout << "Nickname : " << this->_contacts[i].getNickname() << std::endl;
// 			std::cout << "Phone number : " << this->_contacts[i].getPhoneNumber() << std::endl;
// 			std::cout << "Darkest secret : " << this->_contacts[i].getDarkestSecret() << std::endl;
// 			return ;
// 		}
// 		i++;
// 	}
// 	std::cout << "No contact found for the key : " << key << std::endl;
// }
