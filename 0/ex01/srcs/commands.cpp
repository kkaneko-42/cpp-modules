#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include "contact.hpp"

static void	put_contact_info(const std::string info);
static void put_index(size_t index);
static std::string trim_long_str(std::string str);

void Exit(Contact *contacts, size_t *cnt_added)
{
	(void)contacts;
	(void)cnt_added;
	const std::string exit_msg = "Bye!";

	std::cout << exit_msg << std::endl;
	exit(0);
}

void Add(Contact *contacts, size_t *cnt_added)
{
	Contact new_contact;
	std::string input;

	std::cout << "First name:" << std::endl;
	std::cin >> input;
	new_contact.SetFirstName(input);
	
	std::cout << "Last name:" << std::endl;
	std::cin >> input;
	new_contact.SetLastName(input);

	std::cout << "Nick name:" << std::endl;
	std::cin >> input;
	new_contact.SetNickName(input);

	std::cout << "Phone number:" << std::endl;
	std::cin >> input;
	new_contact.SetPhoneNumber(input);

	std::cout << "Darkest secret:" << std::endl;
	std::cin >> input;
	new_contact.SetDarkestSecret(input);

	contacts[*cnt_added % 8] = new_contact;
	++(*cnt_added);
}

void Search(Contact *contacts, size_t *cnt_added)
{
	const size_t total_loop = (*cnt_added < 8) ? *cnt_added : 8;
	std::string num_string;

	for (size_t i = 0; i < total_loop; ++i)
	{
		put_index(i);
		put_contact_info(contacts[i].GetFirstName());
		put_contact_info(contacts[i].GetLastName());
		put_contact_info(contacts[i].GetNickName());
		put_contact_info(contacts[i].GetPhoneNumber());
		put_contact_info(contacts[i].GetDarkestSecret());
		std::cout << std::endl;
	}
}

void Invalid(Contact *contacts, size_t *cnt_added)
{
	(void)contacts;
	(void)cnt_added;
	const std::string invalid_msg = "Invalid command. Try again.";

	std::cout << invalid_msg << std::endl;
}

static void	put_contact_info(const std::string info)
{
	const std::string sep = "|";
	const size_t field_w = 10;
	const size_t trim_len = (info.length() > field_w ? field_w : info.length());
	std::string info_trimed;

	info_trimed = info.substr(0, trim_len);
	if (info.length() > field_w)
		info_trimed = trim_long_str(info_trimed);
	std::cout << std::right << std::setw(field_w) << info_trimed;
	std::cout << sep;
}

static void put_index(size_t index)
{
	const std::string sep = "|";
	const size_t field_w = 10;

	std::cout << std::right << std::setw(field_w) << index;
	std::cout << sep;
}

static std::string trim_long_str(std::string str)
{
	size_t	i;

	i = str.length();
	while (i != 0)
	{
		if (isprint(str[i]))
			break;
		--i;
	}
	if (isprint(str[i]))
		str[i] = '.';
	return (str);
}
