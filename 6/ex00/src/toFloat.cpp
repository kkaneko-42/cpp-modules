#include "Converter.hpp"
#include <exception>
#include <cmath>

static std::string trimInput( const std::string& raw_input ) {
    std::string trimmed = raw_input;

    if (isInt(raw_input)) {
        trimmed += ".0f";
    } else if (isDouble(raw_input)) {
        trimmed += "f";
    }

    return (trimmed);
}

static float checkInfOrNan( const std::string& input ) {
    if (input == "-inff") {
        return (-std::numeric_limits<float>::infinity());
    } else if (input == "+inff" || input == "inff") {
        return (std::numeric_limits<float>::infinity());
    } else if (input == "nanf") {
        return (std::numeric_limits<float>::signaling_NaN());
    } else {
        return (0.0f);
    }
}

static float convertIntegerPart( const std::string& integer_part ) {
    float res = 0;

    for (std::size_t i = 0; i < integer_part.size(); ++i) {
        if (overflowIfMul<float>(res, 10)) {
            throw std::overflow_error("overflow");
        }
        res *= 10;

        float char_as_float = static_cast<float>(integer_part[i] - '0');
        if (overflowIfAdd<float>(res, char_as_float)) {
            throw std::overflow_error("overflow");
        }
        res += char_as_float;
    }

    return (res);
}

static float convertDecimalPart( const std::string& decimal_part ) {
    float res = 0.0f;
    float char_as_float;
    int decimal_place = 1;

    for (std::size_t i = 0; i < decimal_part.size(); ++i, ++decimal_place) {
        try {
            char_as_float = static_cast<float>(decimal_part[i] - '0')
                * ftPow<float>(10.0f, -decimal_place);
        } catch (const std::exception& e) {
            throw;
        }
        
        res += char_as_float;
    }

    return (res);
}

float Converter::toFloat( const std::string& raw_input ) {
    const std::string input = trimInput(raw_input);
    int sgn = 1;
    float res_integer = 0;
    float res_decimal = 0;

    if (!isFloat(input)) {
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
            input.substr(point_pos + 1, input.size() - point_pos - 2)
        );
    } catch(const std::exception& e) {
        throw;
    }

    // check overflow
    if (overflowIfAdd<float>(res_integer, res_decimal)) {
        throw std::overflow_error("overflow");
    }

    return (sgn * (res_integer + res_decimal));
}
