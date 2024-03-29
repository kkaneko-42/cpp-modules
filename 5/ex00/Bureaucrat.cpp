#include <iostream>
#include "Bureaucrat.hpp"

const int Bureaucrat::kHighestGrade = 1;
const int Bureaucrat::kLowestGrade = 150;

Bureaucrat::Bureaucrat( void ) : name_(""), grade_(kLowestGrade)
{
	const std::string kMsg = "default constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : name_(src.getName()), grade_(src.getGrade())
{
	const std::string kMsg = "copy constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name ) : name_(name), grade_(kLowestGrade)
{
	const std::string kMsg = "Naming constructor called";

	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, const int grade ) : name_(name)
{
	const std::string kMsg = "Naming and Grading constructor called";

	if (grade < kHighestGrade)
		throw Bureaucrat::GradeTooHighException(this->getName());
	else if (grade > kLowestGrade)
		throw Bureaucrat::GradeTooLowException(this->getName());
	else
		this->grade_ = grade;
	std::cout << kMsg << std::endl;
}

Bureaucrat::Bureaucrat( const int grade ) : name_("")
{
	const std::string kMsg = "Grading constructor called";

	if (grade < kHighestGrade)
		throw Bureaucrat::GradeTooHighException(this->getName());
	else if (grade > kLowestGrade)
		throw Bureaucrat::GradeTooLowException(this->getName());
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
	if (this->getGrade() == kHighestGrade)
		throw Bureaucrat::GradeTooHighException(this->getName());
	else
		this->grade_ -= 1;
}

void Bureaucrat::Demote( void )
{
	if (this->getGrade() == kLowestGrade)
		throw Bureaucrat::GradeTooLowException(this->getName());
	else
		this->grade_ += 1;
}
