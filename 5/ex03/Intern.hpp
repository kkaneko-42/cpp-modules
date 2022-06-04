#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
	public:
		Intern( void );
		virtual ~Intern( void );

		Form *makeForm( const std::string &name, const std::string &target );
};

#endif //INTERN_HPP
