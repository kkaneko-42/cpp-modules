#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void ShrubberyTest( void );
static void RobotomyTest( void );
static void PresidentialTest( void );

int main( void )
{
	std::cout << "@@@@@ Shrubbery Creation Form @@@@@\n" << std::endl;
	ShrubberyTest();
	std::cout << "@@@@@ Robotomy Request Form @@@@@\n" << std::endl;
	RobotomyTest();
	std::cout << "@@@@@ Presidential Pardon Form @@@@@\n" << std::endl;
	PresidentialTest();
	return (0);
}

static void ShrubberyTest( void )
{
	ShrubberyCreationForm form("home");
	Bureaucrat sign_ok("sign_ok", 145);
	Bureaucrat sign_ko("sign_ko", 146);
	Bureaucrat exec_ok("exec_ok", 137);
	Bureaucrat exec_ko("exec_ko", 138);

	std::cout << form << std::endl;
	try
	{
		sign_ko.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << form << std::endl;
	try {
		form.beSigned(sign_ok);
	} catch ( const std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << form << std::endl;
	try
	{
		form.execute(exec_ko);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << form << std::endl;
	try
	{
		exec_ok.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

static void RobotomyTest( void )
{
	RobotomyRequestForm form("hogehoge");
	Bureaucrat sign_ok("sign_ok", 72);
	Bureaucrat sign_ko("sign_ko", 73);
	Bureaucrat exec_ok("exec_ok", 45);
	Bureaucrat exec_ko("exec_ko", 46);

	std::cout << form << std::endl;
	try
	{
		sign_ko.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << form << std::endl;
	try {
		form.beSigned(sign_ok);
	} catch ( const std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << form << std::endl;
	try
	{
		form.execute(exec_ko);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << form << std::endl;
	try
	{
		exec_ok.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void PresidentialTest( void )
{
	PresidentialPardonForm form("fugafuga");
	Bureaucrat sign_ok("sign_ok", 25);
	Bureaucrat sign_ko("sign_ko", 26);
	Bureaucrat exec_ok("exec_ok", 5);
	Bureaucrat exec_ko("exec_ko", 6);

	std::cout << form << std::endl;
	try
	{
		sign_ko.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << form << std::endl;
	try {
		form.beSigned(sign_ok);
	} catch ( const std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << form << std::endl;
	try
	{
		form.execute(exec_ko);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << form << std::endl;
	try
	{
		exec_ok.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
