#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

Base *generate(void)
{
    srand(time(NULL));
    int class_type = rand() % 3;

    switch (class_type)
    {
        case 1:
            return (new A());
        case 2:
            return (new B());
        case 3:
            return (new C());
        default:
            break;
    }
    return (new A());
}

void identify(Base *p)
{
    std::string classname;

    if (dynamic_cast<A *>(p) != NULL)
        classname = "A";
    else if (dynamic_cast<B *>(p) != NULL)
        classname = "B";
    else if (dynamic_cast<C *>(p) != NULL)
        classname = "C";
    else
        classname = "Invalid";
    std::cout << "p is " << classname << std::endl;
}

void identify(Base &p)
{
    std::string classname;

    try {
        dynamic_cast<A &>(p);
        classname = "A";
    } catch (const std::exception &e) {
        try {
            dynamic_cast<B &>(p);
            classname = "B";
        } catch (const std::exception &e) {
            try {
                dynamic_cast<C &>(p);
                classname = "C";
            } catch (const std::exception &e) {
                classname = "Invalid";
            }
        }
    }
    std::cout << "p is " << classname << std::endl;
}
