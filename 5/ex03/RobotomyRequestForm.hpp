#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		static const int kRequireGradeSign;
		static const int kRequireGradeExec;

		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm( const std::string &target );
		virtual ~RobotomyRequestForm( void );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
