#include "PhoneBook.hpp"
#include <iostream>

std::string	toUpper(std::string str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		++i;
	}
	return str;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	command = "";
	std::string	key = "";
	while (toUpper(command) != "EXIT")
	{
		std::cout << "Enter your command : ";
		std::getline(std::cin, command);
		if (toUpper(command) == "ADD")
			phonebook.addContact();
		else if (toUpper(command) == "SEARCH")
			phonebook.searchContact();
		if (std::cin.eof())
			break ;
	}
	return 0;
}
