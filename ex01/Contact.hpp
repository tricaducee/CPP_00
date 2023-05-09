#ifndef CONTACT_HPP
# define CONTACT_HPP
 #include <string>

	class Contact
	{
		public:
			//Contact() : _first_name("Jhon"), _last_name("Doe"), _nickname("Anonym"), _phone_number("0420424242"), _darkest_secret("I dont exist") {};
			Contact(std::string first_name = "", std::string last_name = "", std::string nickname = "", std::string phone_number = "", std::string darkest_secret = "");
			~Contact();
			std::string getFirstName() const;
			std::string getLastName() const;
			std::string getNickname() const;
			std::string getPhoneNumber() const;
			std::string getDarkestSecret() const;
			void setFirstName(std::string first_name);
			void setLastName(std::string last_name);
			void setNickname(std::string nickname);
			void setPhoneNumber(std::string phone_number);
			void setDarkestSecret(std::string darkest_secret);
		private:
			std::string _first_name;
			std::string _last_name;
			std::string _nickname;
			std::string _phone_number;
			std::string _darkest_secret;
	};
#endif
