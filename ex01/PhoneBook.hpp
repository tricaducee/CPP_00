#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
 #include <string>
 #include "Contact.hpp"
 #define MAX_CONTACTS 8
 #define MAX_LENGTH 10

 namespace format
 {
	std::string formatString(std::string str, unsigned long length);
 }

 class PhoneBook
 {
 	public:
 		PhoneBook(){this->_nb_contacts = 0;};
 		~PhoneBook(){};
 		void addContact();
 		void searchContact() const;
 	private:
 		Contact _contacts[MAX_CONTACTS];
 		int _nb_contacts;
 };

 #endif
 