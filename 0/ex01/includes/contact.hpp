#ifndef CONTACT_CPP
# define CONTACT_CPP

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		void SetFirstName(std::string src);
		void SetLastName(std::string src);
		void SetNickName(std::string src);
		void SetPhoneNumber(std::string src);
		void SetDarkestSecret(std::string src);
		std::string GetFirstName(void) const;
		std::string GetLastName(void) const;
		std::string GetNickName(void) const;
		std::string GetPhoneNumber(void) const;
		std::string GetDarkestSecret(void) const;
};

//commands
void Exit(Contact *contacts, size_t *cnt_added);
void Add(Contact *contacts, size_t *cnt_added);
void Search(Contact *contacts, size_t *cnt_added);
void Invalid(Contact *contacts, size_t *cnt_added);

#endif //CONTACT_CPP