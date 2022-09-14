#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static Form *makeChrubberyCreationForm( const std::string &target );
static Form *makeRobotomyRequestForm( const std::string &target );
static Form *makePresidentialPardonForm( const std::string &target );

Intern::Intern( void )
{
	const std::string kMsg = "Intern default constructor called";

	std::cout << kMsg << std::endl;
}

Intern::Intern( const Intern &src )
{
	const std::string kMsg = "Intern copy constructor called";

	(void)src;
	std::cout << kMsg << std::endl;
}

Intern::~Intern( void )
{
	const std::string kMsg = "Intern destructor called";

	std::cout << kMsg << std::endl;
}

Intern &Intern::operator =( const Intern &rhs )
{
	const std::string kMsg = "Intern assignation operator called";

	(void)rhs;
	std::cout << kMsg << std::endl;
	return (*this);
}

Form *Intern::makeForm( const std::string &name, const std::string &target ) const
{
	const std::string kFormNames[3] = {"shrubbery creation",
										"robotomy request",
										"presidential pardon"};
	Form * (*make_forms[3])( const std::string &target ) =
									{makeChrubberyCreationForm,
									makeRobotomyRequestForm,
									makePresidentialPardonForm};
	const std::string kCreatedMsg = "Intern creates " + name;
	const std::string kDoesNotExistMsg = "Form <" + name + "> doesn't exist.";

	for (std::size_t i = 0; i < 3; ++i)
	{
		if (name == kFormNames[i])
		{
			std::cout << kCreatedMsg << std::endl;
			return ((*make_forms[i])(target));
		}
	}
	std::cout << kDoesNotExistMsg << std::endl;
	return (NULL);
}

static Form *makeChrubberyCreationForm( const std::string &target )
{
	Form *form = new ShrubberyCreationForm(target);

	return (form);
}

static Form *makeRobotomyRequestForm( const std::string &target )
{
	Form *form = new RobotomyRequestForm(target);

	return (form);
}

static Form *makePresidentialPardonForm( const std::string &target )
{
	Form *form = new PresidentialPardonForm(target);

	return (form);
}
