#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac < 2) {
        std::cout << "usage: " << std::endl;
        return EXIT_FAILURE;
    }

    ft::RPN app;
    int ret = EXIT_SUCCESS;
    try {
        std::cout << app.run(av[1]) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        ret = EXIT_FAILURE;
    }

    return ret;
}
