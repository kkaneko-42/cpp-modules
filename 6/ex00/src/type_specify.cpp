#include <string>
#include <iostream>

static bool isDigit( char c )
{
    return ('0' <= c && c <= '9');
}

bool isChar( const std::string& input )
{
    return (input.size() <= 1);
}

bool isInt( const std::string& input )
{
    std::size_t i;

    if (input.size() == 0) {
        return (false);
    }

    i = (input[0] == '-' || input[0] == '+') ? 1 : 0;
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

bool isDouble( const std::string& input )
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
    
    return (isInt(left_of_point) && isInt(right_of_point));
}

bool isFloat( const std::string& input )
{
    const std::size_t point_pos = input.find(".");
    std::string left_of_point;
    std::string right_of_point;

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
    right_of_point = input.substr(point_pos + 1, input.size() - point_pos - 2);
    if (!isInt(left_of_point) || !isInt(right_of_point))
    {
        return (false);
    }

    return (input[input.size() - 1] == 'f');
}
