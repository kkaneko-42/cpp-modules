#include "Converter.hpp"

static bool isPrintable( char c ) {
    return (' ' <= c && c <= '~');
}

static bool overflowIfConversion(int n) {
    return (
        n > static_cast<int>(std::numeric_limits<char>::max())
        || n < static_cast<int>(std::numeric_limits<char>::min())
    );
}

char Converter::toChar( const std::string& input ) {
    int as_int = 0;
    char res;

    if (isChar(input)) {
        res = input[0];
    } else {
        try {
            as_int = toInt(input);
        } catch(const std::exception& e) {
            throw;
        }

        if (overflowIfConversion(as_int)) {
            throw std::overflow_error("overflow");
        }
        res = static_cast<char>(as_int);
    }

    if (!isPrintable(res)) {
        throw std::logic_error(Converter::kNotPrintableMsg);
    }

    return (res);
}
