#include "Converter.hpp"
#include <exception>

static double checkInfOrNan( const std::string& input ) {
    if (input == "-inf") {
        return (-std::numeric_limits<double>::infinity());
    } else if (input == "+inf") {
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
    double res = 1;

    for (std::size_t i = 0; i < decimal_part.size(); ++i) {
        if (underflowIfDiv(res, 10.0)) {
            throw std::underflow_error("toDouble: underflow");
        }
        res /= 10;

        double char_as_double = static_cast<double>(decimal_part[i] - '0');
        if (underflowIfAdd(res, char_as_double)) {
            throw std::underflow_error("toDouble: underflow");
        }
        res += char_as_double;
    }

    return (res - 1.0);
}

double Converter::toDouble( const std::string& input ) {
    int sgn = 1;
    double res_integer = 0;
    double res_decimal = 0;

    if (!isDouble(input)) {
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
