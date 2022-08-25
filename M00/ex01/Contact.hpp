#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
public:
	Contact(std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string darkestSecret);
	Contact(const Contact &other);
	~Contact();
	Contact& operator=(const Contact &other);

private:
	Contact();

private:
	void copyFieldsFrom(const Contact &other);

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif