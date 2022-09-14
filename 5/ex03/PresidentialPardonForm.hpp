#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		static const int kRequireGradeSign;
		static const int kRequireGradeExec;

		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm( const std::string &target );
		virtual ~PresidentialPardonForm( void );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
