#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm( const std::string &target );
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm &operator =( const ShrubberyCreationForm &rhs );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
