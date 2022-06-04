#include <iostream>
#include "Bureaucrat.hpp"

static void occf_test( void );
static void promote_test( void );
static void demote_test( void );

int main( void )
{
	occf_test();
	promote_test();
	demote_test();
	return (0);
}

static void occf_test( void )
{
	Bureaucrat default_construct;
	Bureaucrat name_construct("kkaneko");
	Bureaucrat grade_construct(42);
	Bureaucrat name_and_grade_construct("kkaneko", 42);
	Bureaucrat assign = name_construct;
	Bureaucrat copy(grade_construct);

	std::cout << assign << std::endl;
	std::cout << copy << std::endl;
}

static void promote_test( void )
{
	Bureaucrat kkaneko("kkaneko", 2);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << kkaneko << std::endl;
		try
		{
			kkaneko.Promote();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

static void demote_test( void )
{
	Bureaucrat kkaneko("kkaneko", 149);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << kkaneko << std::endl;
		try
		{
			kkaneko.Demote();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
