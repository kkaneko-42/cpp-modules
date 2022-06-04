#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

static bool draw_shrubbery( std::ofstream &ofs );

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form("Shrubbery creation", "", 145, 137)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src )
	: Form("Shrubbery creation", src.getTarget(), 145, 137)
{
	const std::string kMsg = "Shrubbery copy constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target )
	: Form("Shrubbery creation", target, 145, 137)
{
	const std::string kMsg = "Shrubbery target constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =( const ShrubberyCreationForm &rhs )
{
	const std::string kMsg = "Shrubbery assignation operator called";

	(void)rhs;
	std::cout << kMsg << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void ShrubberyCreationForm::execute( Bureaucrat const &executer ) const
{
	const std::string kIsntSignedMsg = this->getName() + ": Is not signed.";
	const std::string kOutputFileName = this->getTarget() + "_shrubbery";
	const std::string kFileOpenError = this->getTarget() + ": File open error.";
	const std::string kWriteError = this->getTarget() + ": Write error.";

	std::ofstream ofs;

	ofs.open(kOutputFileName.c_str());
	if (!ofs)
		throw std::logic_error(kFileOpenError);
	else if (executer.getGrade() > this->getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else if (this->getIsSigned() == false)
		throw std::logic_error(kIsntSignedMsg);
	else if (draw_shrubbery(ofs))
		throw std::logic_error(kWriteError);
}

static bool draw_shrubbery( std::ofstream &ofs )
{
	const std::string kResourseFile = "shrubbery.txt";
	std::ifstream resource;
	std::string buf;

	resource.open(kResourseFile.c_str(), std::ios::in);
	if (!resource)
		return (true);

	while (!resource.eof())
	{
		std::getline(resource, buf);
		ofs << buf << std::endl;
	}

	return (false);
}
