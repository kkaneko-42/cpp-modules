#include "Converter.hpp"

static bool isPrintable( char c )
{
    return (' ' <= c && c <= '~');
}

char Converter::toChar( const std::string& input ) {
    if (!isChar(input)) {
        // std::cout << kImpossibleMsg;
        std::cout << "Impossible";
        return ('\0');
    }

    if (!isPrintable(input[0])) {
        std::cout << "Non displayable";
        return ('\0');
    }

    return (static_cast<char>(input[0]));
}
