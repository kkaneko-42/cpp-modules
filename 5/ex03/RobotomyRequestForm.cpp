#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::kRequireGradeSign = 72;
const int RobotomyRequestForm::kRequireGradeExec = 45;

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form("Robotomy Request", "",
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src )
	: Form("Robotomy Request", src.getTarget(),
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Robotomy copy constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target )
	: Form("Robotomy Request", target,
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Robotomy target constructor called";

	std::cout << kMsg << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void RobotomyRequestForm::execute( Bureaucrat const &executer ) const
{
	const std::string kSuccessMsg = getTarget() + " has been robotomized!";
	const std::string kFailMsg = getTarget() + "'s robotomization failed...";
	const std::string kDrillNoise = "Rizzz, bzzzzzz";

	srand(time(NULL));
	if (executer.getGrade() > getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else if (getIsSigned() == false)
		throw Form::NotSignedException(getName());
	else
	{
		std::cout << kDrillNoise << std::endl;
		if (rand() % 2 == 0)
			std::cout << kSuccessMsg << std::endl;
		else
			std::cout << kFailMsg << std::endl;
	}
}
