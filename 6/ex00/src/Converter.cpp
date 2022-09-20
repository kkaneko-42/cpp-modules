#include "Converter.hpp"

const std::string kImpossibleMsg = "Impossible";
/*
static bool isPrintable( char c )
{
    return (' ' <= c && c <= '~');
}
*/

Converter::Converter( void )
{ }
/*
Converter::eType
Converter::typeOf( const std::string& input ) {
    const std::size_t nb_type = UNKNOWN;
    bool (*judge[nb_type]) = {isChar, isInt, isFloat, isDouble};

    for (eType type = CHAR; type < nb_type; ++type) {
        if (judge[type](input)) {
            return (type);
        }
    }

    return (UNKNOWN);
}

Converter::Result
Converter::convert( const std::string& input ) {
    Result res;

    res.type = typeOf(input);
    switch (res.type) {
        case CHAR:
            res.value.c = toChar(input);
            break;

        case INT:
            res.value.i = toInt(input);
            break;

        case FLOAT:
            res.value.f = toFloat(input);
            break;

        case DOUBLE:
            res.value.d = toDouble(input);
            break;
        
        default:
            break;
    }

    return (res);
}

char Converter::toChar( const std::string& input ) {
    if (!isChar(input)) {
        std::cout << kImpossibleMsg;
        return ('\0');
    }

    if (!isPrintable(input[0])) {
        std::cout << "Non displayable";
        return ('\0');
    }

    return (static_cast<char>(input[0]));
}

double Converter::toDouble( const std::string& input ) {
    if (!isDouble(input)) {
        std::cout << kImpossibleMsg;
        return (0.0);
    }

    return (0.0);
}
*/