#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat( const std::string &name );
		Bureaucrat( const int grade );
		Bureaucrat( const std::string &name, const int grade );
		virtual ~Bureaucrat( void );

		Bureaucrat &operator =( const Bureaucrat &rhs );

		std::string const &getName( void ) const;
		int getGrade( void ) const;
		void Promote( void );
		void Demote( void );

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException( const std::string &name );
				virtual ~GradeTooHighException( void ) throw();
				virtual const char *what( void ) const throw();
			private:
				std::string name_;
				char *msg;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException( const std::string &name );
				virtual ~GradeTooLowException( void ) throw();
				virtual const char *what( void ) const throw();
			private:
				std::string name_;
				char *msg;
		};

		class GradeIsOutOfRange : public std::exception
		{
			public:
				GradeIsOutOfRange( const std::string &name );
				virtual ~GradeIsOutOfRange( void ) throw();
				virtual const char *what( void ) const throw();
			private:
				std::string name_;
				char *msg;
		};

	private:
		const std::string name_;
		int grade_;
};

std::ostream &operator <<( std::ostream &out, const Bureaucrat &src );

#endif //BUREAUCRAT_HPP
