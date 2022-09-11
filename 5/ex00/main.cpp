#include <iostream>
#include "Bureaucrat.hpp"

static void occfTest( void );
static void promoteTest( void );
static void demoteTest( void );

int main( void )
{
	occfTest();
	promoteTest();
	demoteTest();
	return (0);
}

static void occfTest( void )
{
	Bureaucrat default_construct;
	Bureaucrat name_construct("kkaneko");
	Bureaucrat grade_construct(42);
	Bureaucrat name_and_grade_construct("kkaneko", 42);
	Bureaucrat assigned = grade_construct;
	Bureaucrat copy(grade_construct);

	std::cout << assigned << std::endl;
	std::cout << copy << std::endl;
}

static void promoteTest( void )
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

static void demoteTest( void )
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
