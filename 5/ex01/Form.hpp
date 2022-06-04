#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		typedef Bureaucrat::GradeTooHighException GradeTooHighException;
		typedef Bureaucrat::GradeTooLowException GradeTooLowException;

		Form( void );
		Form( const Form &src );
		Form( const std::string &name, const int sign_grade, const int exec_grade );
		virtual ~Form( void );

		Form &operator =( const Form &rhs );

		std::string const &getName( void ) const;
		bool getIsSigned( void ) const;
		int getLowestGradeToSign( void ) const;
		int getLowestGradeToExec( void ) const;

		void beSigned( const Bureaucrat &bureaucrat );

	private:
		const std::string name_;
		bool is_signed_;
		const int lowest_grade_to_sign_;
		const int lowest_grade_to_exec_;
};

std::ostream &operator <<( std::ostream &out, const Form &rhs );

#endif //FORM_HPP
