#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : name_(""), grade_(150)
{
	const std::string kMsg = "default constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : name_(src.getName()), grade_(src.getGrade())
{
	const std::string kMsg = "copy constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name ) : name_(name), grade_(150)
{
	const std::string kMsg = "Naming constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, const int grade ) : name_(name)
{
	const std::string kMsg = "Naming and Grading constructor called";

	if (grade < 1)
		throw Bureaucrat::GradeTooLowException(this->getName());
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException(this->getName());
	else
		this->grade_ = grade;
	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const int grade ) : name_("")
{
	const std::string kMsg = "Grading constructor called";

	if (grade < 1)
		throw Bureaucrat::GradeTooLowException(this->getName());
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException(this->getName());
	else
		this->grade_ = grade;

	std::cout << kMsg << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	const std::string kMsg = "Destructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat &Bureaucrat::operator =( const Bureaucrat &rhs )
{
	const std::string kMsg = "Assignation operator called";

	if (this != &rhs)
	{
		this->grade_ = rhs.getGrade();
	}
	std::cout << kMsg << std::endl;

	return (*this);
}

std::ostream &operator <<( std::ostream &out, const Bureaucrat &src )
{
	out << src.getName() + ", " << "bureaucrat grade ";
	out << src.getGrade() << "." << std::endl;
	return (out);
}

std::string const &Bureaucrat::getName( void ) const
{
	return (this->name_);
}

int Bureaucrat::getGrade( void ) const
{
	return (this->grade_);
}

void Bureaucrat::Promote( void )
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeIsOutOfRange(this->getName());
	else
		this->grade_ -= 1;
}

void Bureaucrat::Demote( void )
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeIsOutOfRange(this->getName());
	else
		this->grade_ += 1;
}

void Bureaucrat::signForm( Form &form ) const
{
	if (this->getGrade() > form.getLowestGradeToSign())
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because his or her grade is too low." << std::endl;
	}
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm( Form const &form )
{
	const std::string kExecedMsg = this->getName() + " executed " + form.getName();

	if (this->getGrade() > form.getLowestGradeToExec())
		throw Form::GradeTooLowException(this->getName());
	else
	{
		form.execute(*this);
		std::cout << kExecedMsg << std::endl;
	}
}
