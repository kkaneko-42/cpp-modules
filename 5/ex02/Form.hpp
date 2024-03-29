#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	public:
		typedef Bureaucrat::GradeTooHighException GradeTooHighException;
		typedef Bureaucrat::GradeTooLowException GradeTooLowException;
		class NotSignedException : std::exception
		{
			public:
				NotSignedException( const std::string &name );
				virtual ~NotSignedException( void ) throw();
				virtual const char *what( void ) const throw();
			private:
				std::string name_;
				char *msg;
		};

		Form( void );
		Form( const Form &src );
		Form( const std::string &name, const std::string &target,
				const int sign_grade, const int exec_grade );
		virtual ~Form( void );

		Form &operator =( const Form &rhs );

		std::string const &getName( void ) const;
		std::string const &getTarget( void ) const;
		bool getIsSigned( void ) const;
		int getLowestGradeToSign( void ) const;
		int getLowestGradeToExec( void ) const;

		void beSigned( const Bureaucrat &bureaucrat );
		virtual void execute( Bureaucrat const &executer ) const = 0;

	private:
		const std::string name_;
		const std::string target_;
		bool is_signed_;
		const int lowest_grade_to_sign_;
		const int lowest_grade_to_exec_;
};

std::ostream &operator <<( std::ostream &out, const Form &rhs );

#endif //FORM_HPP
