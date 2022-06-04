#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form("Robotomy Request", "", 72, 45)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src )
	: Form("Robotomy Request", src.getTarget(), 72, 45)
{
	const std::string kMsg = "Robotomy copy constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target )
	: Form("Robotomy Request", target, 72, 45)
{
	const std::string kMsg = "Robotomy target constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator =( const RobotomyRequestForm &rhs )
{
	const std::string kMsg = "Robotomy assignation operator called";

	(void)rhs;
	std::cout << kMsg << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void RobotomyRequestForm::execute( Bureaucrat const &executer ) const
{
	const std::string kIsntSignedMsg = this->getName() + ": Is not signed.";
	const std::string kSuccessMsg = this->getTarget() + " has been robotomized!";
	const std::string kFailMsg = this->getTarget() + "'s robotomization failed...";
	const std::string kDrillNoise = "Rizzz, bzzzzzz";

	if (executer.getGrade() > this->getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else if (this->getIsSigned() == false)
		throw std::logic_error(kIsntSignedMsg);
	else
	{
		std::cout << kDrillNoise << std::endl;
		if (rand() % 2 == 0)
			std::cout << kSuccessMsg << std::endl;
		else
			std::cout << kFailMsg << std::endl;
	}
}
