#include "Converter.hpp"
#include <exception>

static std::string trimInput( const std::string& raw_input ) {
    std::string trimmed = raw_input;

    if (isInt(raw_input)) {
        trimmed += ".0";
    } else if (isFloat(raw_input)) {
        trimmed.erase(trimmed.size() - 1);
    }

    return (trimmed);
}

static double checkInfOrNan( const std::string& input ) {
    if (input == "-inf") {
        return (-std::numeric_limits<double>::infinity());
    } else if (input == "+inf" || input == "inf") {
        return (std::numeric_limits<double>::infinity());
    } else if (input == "nan") {
        return (std::numeric_limits<double>::quiet_NaN());
    } else {
        return (0.0f);
    }
}

static double convertIntegerPart( const std::string& integer_part ) {
    double res = 0;

    for (std::size_t i = 0; i < integer_part.size(); ++i) {
        if (overflowIfMul<double>(res, 10)) {
            throw std::overflow_error("toDouble: overflow");
        }
        res *= 10;

        double char_as_double = static_cast<double>(integer_part[i] - '0');
        if (overflowIfAdd<double>(res, char_as_double)) {
            throw std::overflow_error("toDouble: overflow");
        }
        res += char_as_double;
    }

    return (res);
}

static double convertDecimalPart( const std::string& decimal_part ) {
    double res = 0.0;
    double char_as_double;
    int decimal_place = 1;

    for (std::size_t i = 0; i < decimal_part.size(); ++i, ++decimal_place) {
        try {
            char_as_double = static_cast<double>(decimal_part[i] - '0')
                * ftPow<double>(10.0, -decimal_place);
        } catch (const std::exception& e) {
            throw;
        }
        
        res += char_as_double;
    }

    return (res);
}

double Converter::toDouble( const std::string& raw_input ) {
    const std::string input = trimInput(raw_input);
    int sgn = 1;
    double res_integer = 0;
    double res_decimal = 0;

    if (!isDouble(input)) {
        throw std::logic_error(Converter::kImpossibleMsg);
    }
    if (checkInfOrNan(input)) {
        return (checkInfOrNan(input));
    }

    const std::size_t start_pos = (input[0] == '+' || input[0] == '-') ? 1 : 0;
    const std::size_t point_pos = input.find(".");
    // check sign
    if (input[0] == '-') {
        sgn = -1;
    }

    try {
        res_integer = convertIntegerPart(
            input.substr(start_pos, point_pos - start_pos)
        );
        res_decimal = convertDecimalPart(
            input.substr(point_pos + 1, input.size() - point_pos - 1)
        );
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        res_integer = 0.0;
        res_decimal = 0.0;
    }

    // check overflow
    if (overflowIfAdd<double>(res_integer, res_decimal)) {
        std::cerr << "toDouble: overflow" << std::endl;
        return (0.0);
    }

    return (sgn * (res_integer + res_decimal));
}
