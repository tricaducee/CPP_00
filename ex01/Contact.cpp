#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return this->_first_name;
}

std::string Contact::getLastName() const
{
	return this->_last_name;
}

std::string Contact::getNickname() const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkest_secret;
}

void Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
