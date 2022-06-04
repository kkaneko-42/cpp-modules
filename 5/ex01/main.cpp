#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void occf_test( void );
static void beSignedTest( void );
static void signFormTest( void );

int main( void )
{
	std::cout << "@@@@@ occf test @@@@@" << std::endl;
	occf_test();
	std::cout << "@@@@@ besigned test @@@@@" << std::endl;
	beSignedTest();
	std::cout << "@@@@@ sign form test @@@@@" << std::endl;
	signFormTest();
	return (0);
}

static void occf_test( void )
{
	Form default_construct;
	Form params_construct("order", 24, 42);
	try
	{
		Form ko_construct("ko", 151, 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form assign = params_construct;
	Form copy(params_construct);

	std::cout << params_construct << std::endl;
	std::cout << copy << std::endl;
}

static void beSignedTest( void )
{
	Form form("order", 42, 42);
	Bureaucrat ok("ok", 42);
	Bureaucrat ko("ko", 43);

	std::cout << form << std::endl;
	try
	{
		form.beSigned(ko);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}

	std::cout << form << std::endl;
	try
	{
		form.beSigned(ok);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}

	std::cout << form << std::endl;
}

static void signFormTest( void )
{
	Form form("order", 1, 42);
	Bureaucrat ok("ok", 1);
	Bureaucrat ko("ko", 2);

	std::cout << form << std::endl;
	ko.signForm(form);
	std::cout << form << std::endl;
	ok.signForm(form);
	std::cout << form << std::endl;
}
