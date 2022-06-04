#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : name_(""),
					is_signed_(false),
					lowest_grade_to_sign_(1),
					lowest_grade_to_exec_(1)
{
	const std::string kMsg = "Form default constructor called";

	std::cout << kMsg << std::endl;
}

Form::Form( const Form &src ) : name_(src.getName()),
								is_signed_(src.getIsSigned()),
								lowest_grade_to_sign_(src.getLowestGradeToSign()),
								lowest_grade_to_exec_(src.getLowestGradeToExec())
{
	const std::string kMsg = "Form copy constructor called";

	std::cout << kMsg << std::endl;
}

Form::Form( const std::string &name, const int sign_grade, const int exec_grade) :
	name_(name), is_signed_(false), lowest_grade_to_sign_(sign_grade), lowest_grade_to_exec_(exec_grade)
{
	const int kSignGrade = this->getLowestGradeToSign();
	const int kExecGrade = this->getLowestGradeToExec();

	if (kSignGrade < 1 || kExecGrade < 1)
		throw Form::GradeTooHighException(name);
	else if (kSignGrade > 150 || kExecGrade > 150)
		throw Form::GradeTooLowException(name);

}

Form::~Form( void )
{
	const std::string kMsg = "Form destructor called";

	std::cout << kMsg << std::endl;
}

Form &Form::operator =( const Form &rhs )
{
	const std::string kMsg = "Form assignation operator called";

	if (this != &rhs)
	{
		this->is_signed_ = rhs.getIsSigned();
	}
	std::cout << kMsg << std::endl;
	return (*this);
}

std::ostream &operator <<( std::ostream &out, const Form &rhs )
{
	out << "==== " << rhs.getName() << " ====" << std::endl;
	out << "Is signed: " << rhs.getIsSigned() << std::endl;
	out << "Lowest grade to sign: " << rhs.getLowestGradeToSign() << std::endl;
	out << "Lowest grade to exec: " << rhs.getLowestGradeToExec() << std::endl;

	return (out);
}

std::string const &Form::getName( void ) const
{
	return (this->name_);
}

bool Form::getIsSigned( void ) const
{
	return (this->is_signed_);
}

int Form::getLowestGradeToSign( void ) const
{
	return (this->lowest_grade_to_sign_);
}

int Form::getLowestGradeToExec( void ) const
{
	return (this->lowest_grade_to_exec_);
}

void Form::beSigned( const Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() > lowest_grade_to_sign_)
		throw Form::GradeTooLowException(this->getName());
	else
		this->is_signed_ = true;
}
