#include <iostream>
#include <string>
#include "contact.hpp"

void Contact::SetFirstName(std::string src)
{
	this->first_name_ = src;
}

void Contact::SetLastName(std::string src)
{
	this->last_name_ = src;
}

void Contact::SetNickName(std::string src)
{
	this->nick_name_ = src;
}

void Contact::SetPhoneNumber(std::string src)
{
	this->phone_number_ = src;
}

void Contact::SetDarkestSecret(std::string src)
{
	this->darkest_secret_ = src;
}

std::string Contact::GetFirstName(void) const
{
	return (this->first_name_);
}

std::string Contact::GetLastName(void) const
{
	return (this->last_name_);
}

std::string Contact::GetNickName(void) const
{
	return (this->nick_name_);
}

std::string Contact::GetPhoneNumber(void) const
{
	return (this->phone_number_);
}

std::string Contact::GetDarkestSecret(void) const
{
	return (this->darkest_secret_);
}
