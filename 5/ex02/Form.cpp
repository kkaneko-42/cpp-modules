#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : name_(""),
					target_(""),
					is_signed_(false),
					lowest_grade_to_sign_(Bureaucrat::kHighestGrade),
					lowest_grade_to_exec_(Bureaucrat::kHighestGrade)
{
	const std::string kMsg = "Form default constructor called";

	std::cout << kMsg << std::endl;
}

Form::Form( const Form &src ) : name_(src.getName()),
								target_(src.getTarget()),
								is_signed_(src.getIsSigned()),
								lowest_grade_to_sign_(src.getLowestGradeToSign()),
								lowest_grade_to_exec_(src.getLowestGradeToExec())
{
	const std::string kMsg = "Form copy constructor called";

	std::cout << kMsg << std::endl;
}

Form::Form( const std::string &name, const std::string &target, const int sign_grade, const int exec_grade) :
	name_(name), target_(target),
	is_signed_(false),
	lowest_grade_to_sign_(sign_grade), lowest_grade_to_exec_(exec_grade)
{
	const int kSignGrade = this->getLowestGradeToSign();
	const int kExecGrade = this->getLowestGradeToExec();

	if (kSignGrade < Bureaucrat::kHighestGrade || kExecGrade < Bureaucrat::kHighestGrade)
		throw Form::GradeTooHighException(name);
	else if (kSignGrade > Bureaucrat::kLowestGrade || kExecGrade > Bureaucrat::kLowestGrade)
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
	out << "Target: " << rhs.getTarget() << std::endl;
	out << "Is signed: " << rhs.getIsSigned() << std::endl;
	out << "Lowest grade to sign: " << rhs.getLowestGradeToSign() << std::endl;
	out << "Lowest grade to exec: " << rhs.getLowestGradeToExec() << std::endl;

	return (out);
}

std::string const &Form::getName( void ) const
{
	return (this->name_);
}

std::string const &Form::getTarget( void ) const
{
	return (this->target_);
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

void Form::execute( Bureaucrat const &executer ) const
{
	(void)executer;
}
