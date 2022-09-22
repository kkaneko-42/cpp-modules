#include "Converter.hpp"

const std::string Converter::kImpossibleMsg = "impossible";
const std::string Converter::kNotPrintableMsg = "Non displayable";

Converter::Converter( void )
{ }

Converter::eType
Converter::typeOf( const std::string& input ) {
    const std::size_t nb_type = UNKNOWN;
    bool (*judge[nb_type])(const std::string&) = {
        isChar, isInt, isFloat, isDouble
    };

    for (std::size_t type = static_cast<std::size_t>(CHAR); type < nb_type; ++type) {
        if (judge[type](input)) {
            return (static_cast<eType>(type));
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

std::ostream& operator<<( std::ostream& os, const Converter::Result &res ) {
    Converter::uValue value = res.value;

    os << "{type: " << res.type << ", value: ";
    switch (res.type)
    {
        case Converter::CHAR:
            os << value.c;
            break;
        case Converter::INT:
            os << value.i;
            break;
        case Converter::FLOAT:
            os << value.f;
            break;
        case Converter::DOUBLE:
            os << value.d;
            break;
        default:
            os << "unknown";
            break;
    }
    os << "}";

    return (os);
}

std::ostream& operator<<( std::ostream& os, const Converter::eType type ) {
    switch (type)
    {
        case Converter::CHAR:
            os << "char";
            break;
        case Converter::INT:
            os << "int";
            break;

        case Converter::FLOAT:
            os << "float";
            break;

        case Converter::DOUBLE:
            os << "double";
            break;
        
        default:
            os << "unknown";
            break;
    }

    return (os);
}
