#include "Converter.hpp"

const std::string kImpossibleMsg = "Impossible";

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

*/