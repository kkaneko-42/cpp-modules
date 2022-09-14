#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

static bool copyTarget( const std::string &target_name, std::string &content );
static bool draw_shrubbery( const std::string &output_name, const std::string &target_content );

const int ShrubberyCreationForm::kRequireGradeSign = 145;
const int ShrubberyCreationForm::kRequireGradeExec = 137;

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form("Shrubbery creation", "",
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Shruberry constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src )
	: Form("Shrubbery creation", src.getTarget(),
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Shrubbery copy constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target )
	: Form("Shrubbery creation", target,
	kRequireGradeSign, kRequireGradeExec)
{
	const std::string kMsg = "Shrubbery target constructor called";

	std::cout << kMsg << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	const std::string kMsg = "Shruberry destructor called";

	std::cout << kMsg << std::endl;
}

void ShrubberyCreationForm::execute( Bureaucrat const &executer ) const
{
	const std::string target = getTarget();
	const std::string kOutputFilename = target + "_shrubbery";
	const std::string kSystemErrorMsg = target + ": System error.";
	std::string content;

	if (executer.getGrade() > getLowestGradeToExec())
		throw Form::GradeTooLowException(executer.getName());
	else if (getIsSigned() == false)
		throw Form::NotSignedException(getName());
	else if (copyTarget(target, content) || draw_shrubbery(kOutputFilename, content))
		throw std::runtime_error(kSystemErrorMsg);
}

static bool copyTarget( const std::string &target_name, std::string &content )
{
	std::ifstream target;
	std::string buf;

	target.open(target_name.c_str(), std::ios::in);
	// Not an error if target file is not exists
	if (!target)
		return (false);

	while (!target.eof())
	{
		std::getline(target, buf);
		if (target.fail())
			return (true);
		content += buf + "\n";
	}

	return (false);
}

static bool draw_shrubbery( const std::string &output_name, const std::string &target_content )
{
	const std::string kResourseFile = "shrubbery.txt";
	std::ifstream resource;
	std::ofstream output;
	std::string buf;

	resource.open(kResourseFile.c_str(), std::ios::in);
	if (!resource)
		return (true);
	output.open(output_name.c_str(), std::ios::out);
	if (!output)
		return (true);

	output << target_content;
	while (!resource.eof())
	{
		std::getline(resource, buf);
		if (resource.fail())
			return (true);
		output << buf << std::endl;
	}

	return (false);
}
