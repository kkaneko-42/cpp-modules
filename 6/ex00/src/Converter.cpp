#include "Converter.hpp"

const std::string kImpossibleMsg = "Impossible";

Converter::Converter( void )
{ }

// cal a^b
static double ftPow( double a, int b )
{
    double res = 1;

    // if (b > 0)
    while (b > 0)
    {
        res *= a;
        --b;
    }

    // if (b < 0)
    while (b < 0)
    {
        res /= a;
        ++b;
    }

    return (res);
}

static bool isDigit( char c )
{
    return ('0' <= c && c <= '9');
}

static bool isPrintable( char c )
{
    return (' ' <= c && c <= '~');
}

static bool isChar( const std::string& input )
{
    return (input.size() <= 1);
}

static bool isInt( const std::string& input )
{
    std::size_t i = (input[0] == '-' || input[0] == '+') ? 1 : 0;

    while (i < input.size())
    {
        if (!isDigit(input[i]))
        {
            return (false);
        }
        ++i;
    }

    return (true);
}

static bool isDouble( const std::string& input )
{
    const std::size_t point_pos = input.find(".");
    std::string left_of_point;
    std::string right_of_point;

    // inf, nan
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        return (true);
    }

    // '.' not found
    if (point_pos == std::string::npos)
    {
        return (false);
    }

    left_of_point = input.substr(0, point_pos);
    right_of_point = input.substr(point_pos + 1, input.size() - point_pos);
    
    return (!isInt(left_of_point) || !isInt(right_of_point));
}

static bool isFloat( const std::string& input )
{
    const std::size_t point_pos = input.find(".");
    std::string left_of_point;
    std::string right_of_point;
    std::size_t i = (input[0] == '-' || input[0] == '+') ? 1 : 0;

    // inf, nan
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        return (true);
    }

    // '.' not found
    if (point_pos == std::string::npos)
    {
        return (false);
    }

    left_of_point = input.substr(0, point_pos);
    right_of_point = input.substr(point_pos + 1, input.size() - point_pos - 1);
    if (!isInt(left_of_point) || !isInt(right_of_point))
    {
        return (false);
    }

    return (input[len - 1] == 'f');
}

Converter::eType
Converter::typeOf( const std::string& input )
{
    const std::size_t nb_type = UNKNOWN;
    bool (*judge[nb_type]) = {isChar, isInt, isFloat, isDouble};

    for (eType type = CHAR; type < nb_type; ++type)
    {
        if (judge[type](input))
        {
            return (type);
        }
    }

    return (UNKNOWN);
}

Converter::Result
Converter::convert( const std::string& input )
{
    Result res;

    res.type = typeOf(input);
    switch (res.type)
    {
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

char Converter::toChar( const std::string& input )
{
    if (!isChar(input))
    {
        std::cout << kImpossibleMsg;
        return ('\0');
    }

    if (!isPrintable(input[0]))
    {
        std::cout << "Non displayable";
        return ('\0');
    }

    return (static_cast<char>(input[0]))
}

int Converter::toInt( const std::string& input )
{
    int sgn = 1;
    std::size_t i = 0;
    unsigned int n = 0;

    if (!isInt(input))
    {
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
    while (i < input.size())
    {
        n = (n * 10) + (static_cast<char>(input[i]) - '0');
        ++i;
    }

    return (sgn * static_cast<int>(n));
}

float Converter::toFloat( const std::string& input )
{
    std::string point_pos;
    int sgn = 1;
    std::size_t i = 0;
    float res = 0;

    if (!isFloat(input))
    {
        std::cout << kImpossibleMsg;
        return (0.0f);
    }

    /* inf, nan */
    if (input == "-inff")
    {
        return (-numeric_limits<float>::infinity());
    }
    else if (input == "+inff")
    {
        return (numeric_limits<float>::infinity());
    }
    else if (input == "nan")
    {
        return (numeric_limits<float>::quiet_NaN());
    }

    // check sign
    if (input[0] == '-')
    {
        sgn = -1;
        i = 1;
    }

    point_pos = input.find(".");
    while (i < point_pos)
    {
        res = (res * 10) + (input[i] - '0');
        ++i;
    }
    i = input.size() - 1;
    while (i != point_pos)
    {
        res += (input[i] - '0') * ftPow(10, -static_cast<int>(i - ));
        --i;
    }

    return (res);
}

double Converter::toDouble( const std::string& input )
{
    if (!isDouble(input))
    {
        std::cout << kImpossibleMsg;
        return (0.0);
    }
}
