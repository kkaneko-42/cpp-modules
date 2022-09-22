#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main( void )
{
	A a;
	B b;
	C c;
	Base *someone = generate();
	
	identify(a);
	identify(&a);
	identify(b);
	identify(&b);
	identify(c);
	identify(&c);

	std::cout << "=== About generating ===" << std::endl;
	// std::cout << "Actual: " << typeid(*someone).name() << std::endl;
	std::cout << "My identify: ";
	identify(*someone);
	return (0);
}
