#include "Bureaucrat.hpp"
#include <string.h>

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string &name )
{
	std::string str_msg = name + ": Grade is too high.";

	this->name_ = name;
	msg = new char[str_msg.length() + 1];
	strcpy(msg, str_msg.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	delete[] msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string &name )
{
	std::string str_msg = name + ": Grade is too low.";

	this->name_ = name;
	msg = new char[str_msg.length() + 1];
	strcpy(msg, str_msg.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	delete[] msg;
}

Bureaucrat::GradeIsOutOfRange::GradeIsOutOfRange( const std::string &name )
{
		std::string str_msg = name + ": Grade is out of range.";

	this->name_ = name;
	msg = new char[str_msg.length() + 1];
	strcpy(msg, str_msg.c_str());
}

Bureaucrat::GradeIsOutOfRange::~GradeIsOutOfRange( void ) throw()
{
	delete[] msg;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return (msg);
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return (msg);
}

const char *Bureaucrat::GradeIsOutOfRange::what( void ) const throw()
{
	return (msg);
}
