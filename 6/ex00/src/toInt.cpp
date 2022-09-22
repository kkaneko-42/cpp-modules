#include "Converter.hpp"

static std::string trimInput( const std::string& raw_input ) {
    std::string trimmed = raw_input;
    std::size_t point_pos = raw_input.find(".");

    if ((isFloat(raw_input) || isDouble(raw_input))
        && point_pos != std::string::npos) {
        
        trimmed.erase(trimmed.begin() + point_pos, trimmed.end());
    }

    return (trimmed);
}

static int doConvert( const std::string& input ) {
    int n = 0;
    std::size_t i = (input[0] == '-' || input[1] == '+') ? 1 : 0;

    while (i < input.size()) {
        if (overflowIfMul<int>(n, 10)) {
            throw std::overflow_error("overflow");
        }
        n *= 10;

        int char_as_num = static_cast<int>(static_cast<char>(input[i] - '0'));
        if (overflowIfAdd<int>(n, char_as_num)) {
            throw std::overflow_error("overflow");
        }
        n += char_as_num;
        ++i;
    }

    return (n);
}

int Converter::toInt( const std::string& raw_input ) {
    const std::string input = trimInput(raw_input);
    int sgn = 1;
    int n = 0;

    if (!isInt(input)) {
        throw std::logic_error(Converter::kImpossibleMsg);
    }

    // check sign
    if (static_cast<char>(input[0]) == '-') {
        sgn = -1;
    }

    // convert
    try {
        n = doConvert(input);
    } catch (const std::exception& e) {
        throw;
    }

    return (sgn * static_cast<int>(n));
}
