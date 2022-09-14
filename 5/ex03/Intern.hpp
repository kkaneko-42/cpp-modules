#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( const Intern &src );
		~Intern( void );

		Intern &operator =( const Intern &rhs );

		Form *makeForm( const std::string &name, const std::string &target ) const;
};

#endif //INTERN_HPP
