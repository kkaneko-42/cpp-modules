#include "Converter.hpp"
#include <exception>

static float checkInfOrNan( const std::string& input ) {
    if (input == "-inff") {
        return (-std::numeric_limits<float>::infinity());
    } else if (input == "+inff") {
        return (std::numeric_limits<float>::infinity());
    } else if (input == "nan") {
        return (std::numeric_limits<float>::quiet_NaN());
    } else {
        return (0.0f);
    }
}

static float convertIntegerPart( const std::string& integer_part ) {
    float res = 0;

    for (std::size_t i = 0; i < integer_part.size(); ++i) {
        if (overflowIfMul<float>(res, 10)) {
            throw std::overflow_error("toFloat: overflow");
        }
        res *= 10;

        float char_as_float = static_cast<float>(integer_part[i] - '0');
        if (overflowIfAdd<float>(res, char_as_float)) {
            throw std::overflow_error("toFloat: overflow");
        }
        res += char_as_float;
    }

    return (res);
}

static float convertDecimalPart( const std::string& decimal_part ) {
    float res = 1;

    for (std::size_t i = 0; i < decimal_part.size(); ++i) {
        if (underflowIfDiv(res, 10.0f)) {
            throw std::underflow_error("toFloat: underflow");
        }
        res /= 10;

        float char_as_float = static_cast<float>(decimal_part[i] - '0');
        if (underflowIfAdd(res, char_as_float)) {
            throw std::underflow_error("toFloat: underflow");
        }
        res += char_as_float;
    }

    return (res - 1.0f);
}

float Converter::toFloat( const std::string& input ) {
    int sgn = 1;
    float res_integer = 0;
    float res_decimal = 0;

    if (!isFloat(input)) {
        // std::cout << Converter::kImpossibleMsg;
        std::cout << "Impossible";
        return (0.0f);
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
        std::cerr << e.what() << std::endl;
        res_integer = 0.0f;
        res_decimal = 0.0f;
    }

    // check overflow
    if (overflowIfAdd<float>(res_integer, res_decimal)) {
        std::cerr << "toFloat: overflow" << std::endl;
        return (0.0f);
    }

    return (sgn * (res_integer + res_decimal));
}
