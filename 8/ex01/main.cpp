#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"
#define TEST_KO "\x1b[31mKO\x1b[39m"
#define TEST_OK "\x1b[32mOK\x1b[39m"

static void subjectTest( void );
static void bigInputTest( void );

int main()
{
    srand(time(NULL));
    subjectTest();
    bigInputTest();

	return (0);
}

static void subjectTest( void ) {
    Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void bigInputTest( void ) {
    const unsigned int test_size = 20000;
    Span sp = Span(test_size);
    std::set<int> set;

    sp.addNumber(1);
    set.insert(1);
    sp.addNumber(2);
    set.insert(2);

    for (size_t i = 2; i < test_size; ++i) {
        int value = rand();
        sp.addNumber(value);
        set.insert(value);
    }

    if (sp.shortestSpan() != 1) {
        std::cout << TEST_KO << std::endl;
    } else if (sp.longestSpan() != static_cast<unsigned int>(*set.rbegin() - *set.begin())) {
        std::cout << TEST_KO << std::endl;
    } else {
        std::cout << TEST_OK << std::endl;
    }
}
