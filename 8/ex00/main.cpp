#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "easyfind.hpp"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET_COLOR "\x1b[39m"

static void assignRandomValues( std::vector<int>& vec );
static int foundCaseTest( int len );
static int randomTest( int len, int count );

int main( int ac, char** av )
{
    srand(time(NULL));
    int nb_ko = 0;
    int len;
	
    if (ac >= 2) {
        len = atoi(av[1]);
    } else {
        len = 42;
    }

    nb_ko += foundCaseTest(len);
    nb_ko += randomTest(len, 100);

    if (nb_ko != 0) {
        std::cout << RED << "KO: " << nb_ko << RESET_COLOR << std::endl;
    } else {
        std::cout << GREEN << "All OK" << RESET_COLOR << std::endl;
    }

	return (nb_ko);
}

static void assignRandomValues( std::vector<int>& vec ) {
    for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); ++it) {
        *it = rand();
    }
}

static int foundCaseTest( int len ) {
    int nb_ko = 0;
    std::vector<int> a(len);
    assignRandomValues(a);

    std::cout << "=== found case ===" << std::endl;
    for (std::vector<int>::iterator it = a.begin(); it < a.end(); ++it) {
        std::vector<int>::iterator std_res = std::find(a.begin(), a.end(), *it);
        std::vector<int>::iterator ft_res = easyfind(a, *it);

        std::cout << "std pos: " << std_res - a.begin() << std::endl;
        std::cout << "ft pos: " << ft_res - a.begin() << std::endl;
        if (std_res != ft_res) {
            std::cout << RED << "KO" << RESET_COLOR << std::endl;
            ++nb_ko;
        } else {
            std::cout << GREEN << "OK" << RESET_COLOR << std::endl;
        }
    }

	return (nb_ko);
}

static int randomTest( int len, int count ) {
    int nb_ko = 0;
    std::vector<int> a(len);
    assignRandomValues(a);

    std::cout << "=== random case ===" << std::endl;
    for (int i = 0; i < count; ++i) {
        int value = rand();
        std::vector<int>::iterator std_res = std::find(a.begin(), a.end(), value);
        std::vector<int>::iterator ft_res = easyfind(a, value);

        std::cout << "std pos: " << std_res - a.begin() << std::endl;
        std::cout << "ft pos: " << ft_res - a.begin() << std::endl;
        if (std_res != ft_res) {
            std::cout << RED << "KO" << RESET_COLOR << std::endl;
            ++nb_ko;
        } else {
            std::cout << GREEN << "OK" << RESET_COLOR << std::endl;
        }
    }

    return (nb_ko);
}
