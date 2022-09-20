#include "Converter.hpp"

static int convertToInt( const std::string& input ) {
    unsigned int 
}

int Converter::toInt( const std::string& input ) {
    int sgn = 1;
    std::size_t i = 0;
    unsigned int n = 0;

    if (!isInt(input)) {
        std::cout << kImpossibleMsg;
        return (0);
    }

    // check sign
    if (static_cast<char>(input[0]) == '-')
    {
        sgn = -1;
        i = 1;
    }

    // convert
    while (i < input.size()) {
        if (overflowIfMul<unsigned int>(n, 10)) {
            std::cout << kImpossibleMsg;
            return (0);
        }
        n *= 10;

        int char_as_num = static_cast<int>(static_cast<char>(input[i] - '0'));
        if (overflowIfAdd<unsigned int>(n, char_as_num)) {
            std::cout << kImpossibleMsg;
            return (0);
        }
        n += char_as_num;
        ++i;
    }

    return (sgn * static_cast<int>(n));
}
