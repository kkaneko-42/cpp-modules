#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm( const std::string &target );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm &operator =( const RobotomyRequestForm &rhs );

		virtual void execute( Bureaucrat const &executer ) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
