#include <iostream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::kRequireGradeSign = 25;
const int PresidentialPardonForm::kRequireGradeExec = 5;

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form("Presidential Pardon", "",
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src )
	: Form("Presidential Pardon", src.getTarget(),
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Presidential copy constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target )
	: Form("Presidential Pardon", target,
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Presidential target constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const &executer ) const
{
	const std::string kPardonedMsg = getTarget() + " has been pardoned by Zaphod Beeblebrox.";

	if (executer.getGrade() > getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else if (getIsSigned() == false)
		throw Form::NotSignedException(getName());
	else
		std::cout << kPardonedMsg << std::endl;
}
