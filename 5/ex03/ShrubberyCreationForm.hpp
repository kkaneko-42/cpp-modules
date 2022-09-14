#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		static const int kRequireGradeSign;
		static const int kRequireGradeExec;

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm( const std::string &target );
		virtual ~ShrubberyCreationForm( void );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
