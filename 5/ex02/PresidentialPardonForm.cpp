#include <iostream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form("Presidential Pardon", "", 25, 5)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src )
	: Form("Presidential Pardon", src.getTarget(), 25, 5)
{
	const std::string kMsg = "Presidential copy constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target )
	: Form("Presidential Pardon", target, 25, 5)
{
	const std::string kMsg = "Presidential target constructor called";

	std::cout << kMsg << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator =( const PresidentialPardonForm &rhs )
{
	const std::string kMsg = "Presidential assignation operator called";

	(void)rhs;
	std::cout << kMsg << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const &executer ) const
{
	const std::string kPardonedMsg = this->getTarget() + " has been pardoned by Zaphod Beeblebrox.";

	if (executer.getGrade() > this->getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else
		std::cout << kPardonedMsg << std::endl;
}
