#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm( const std::string &target );
		virtual ~PresidentialPardonForm( void );

		PresidentialPardonForm &operator =( const PresidentialPardonForm &rhs );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
