#include "Converter.hpp"

static int doConvert( const std::string& input ) {
    int n = 0;
    std::size_t i = (input[0] == '-' || input[1] == '+') ? 1 : 0;

    while (i < input.size()) {
        if (overflowIfMul<int>(n, 10)) {
            throw std::overflow_error("toInt: overflow");
        }
        n *= 10;

        int char_as_num = static_cast<int>(static_cast<char>(input[i] - '0'));
        if (overflowIfAdd<int>(n, char_as_num)) {
            throw std::overflow_error("toInt: overflow");
        }
        n += char_as_num;
        ++i;
    }

    return (n);
}

int Converter::toInt( const std::string& input ) {
    int sgn = 1;
    int n = 0;

    if (!isInt(input)) {
        // std::cout << Converter::kImpossibleMsg;
        std::cout << "Impossible";
        return (0);
    }

    // check sign
    if (static_cast<char>(input[0]) == '-')
    {
        sgn = -1;
    }

    // convert
    try {
        n = doConvert(input);
    } catch (const std::exception& e) {
        // std::cout << Converter::kImpossibleMsg;
        std::cerr << e.what() << std::endl;
        n = 0;
    }

    return (sgn * static_cast<int>(n));
}
